# Lab 4 controller skeleton 
#
# Based on of_tutorial by James McCauley

from pox.core import core
import pox.openflow.libopenflow_01 as of
from pox.lib import util
import time

log = core.getLogger()

class Firewall (object):
  """
  A Firewall object is created for each switch that connects.
  A Connection object for that switch is passed to the __init__ function.
  """
  def __init__ (self, connection):
    # Keep track of the connection to the switch so that we can
    # send it messages!
    self.connection = connection

    # This binds our PacketIn event listener
    connection.addListeners(self)

    self.ping_times = {}

  def do_firewall (self, packet, packet_in, port):
    # The code in here will be executed for every packet

    def accept():
      # Write code for an accept function
      #Install flow table entry with specified timeouts
      msg = of.ofp_packet_out()
      msg.match = of.ofp_match.from_packet(packet)
      msg.idle_timeout = 45  # idle Timeout
      msg.hard_timeout = 400  # hard Timeout
      msg.data = packet_in
      msg.actions.append(of.ofp_action_output(port = of.OFPP_FLOOD))
      msg.in_port = port
      self.connection.send(msg)
      print("Packet Accepted - Flow Table Installed on Switches")


    def drop(duration = None):
      # Write code for a drop function
      if duration is not None:
        if isinstance(duration, tuple):
          duration = (duration, duration)
        msg = of.ofp_flow_mod()
        msg.match = of.ofp_match.from_packet(packet)
        msg.idle_timeout = 45
        msg.hard_timout = 400
        msg.buffer_id = packet_in.buffer_id
        self.connection.send(msg)
      elif packet_in.buffer_id is not None:
        msg = of.ofp_packet_out()
        msg.buffer_id = packet_in.buffer_id
        msg.in_port = port
        self.connection.send(msg)

      print("Packet Dropped - Flow Table Installed on Switches")

    # Write firewall code 
    ip = packet.find('ipv4')
    if packet.find('arp'):
      accept()
    elif packet.find('icmp'):
      if packet.dst == "dnsServer":
        src_ip = ip.srcip
        if src_ip in self.ping_times:
          repeat_time = self.ping_times[src_ip]
          if repeat_time > 1000:
            drop()
        self.ping_times[src_ip] = repeat_time + 1
        accept()
      else:
        accept()
    elif packet.find('tcp'):
      if (packet.src in {"facultyWS", "facultyPC", "labWS", "studentPC", "itWS", "itPC"} and packet.dts == "webServer"):
        accept()
      elif (packet.src == "webServer" and packet.dst in {"facultyWS", "facultyPC", "labWS", "studentPC", "itWS", "itPC"}):
        accept()
      elif (packet.src in {"facultyWS", "facultyWS"} and packet.dst == "examServer"):
        accept()
      elif (packet.src == "examServer" and packet.dst in {"facultyWS", "facultyWS"}):
        accept()
      elif (packet.src in {"facultyWS", "facultyPC", "labWS", "studentPC", "itWS", "itPC"} and packet.dst in {"facultyWS", "facultyPC", "labWS", "studentPC", "itWS", "itPC"}):
        accept()
      elif (packet.src in {"facultyWS", "labWS", "itWS"} and packet.dst == "printer"):
        accept()
      elif (packet.src == "printer" and packet.dst in {"facultyWS", "labWS", "itWS"}):
        accept()
      elif (packet.src == "guestPC" and packet.dst in {"webServer", "dnsServer"}):
        accept()
      elif (packet.src in {"webServer", "dnsServer"} and packet.dst == "guestPC"):
        accept()
      elif (packet.src == "trustedPC" and packet.dst in {"webServer", "dnsServer", "studentPC"}):
        accept()
      elif (packet.src in {"webServer", "dnsServer", "studentPC"} and packet.dst == "trustedPC"):
        accept()
      else:
        drop()
    elif packet.find('udp'):
      if (packet.src in {"facultyWS", "facultyPC", "labWS", "studentPC", "itWS", "itPC"} and packet.dts == "dnsServer"):
        accept()
      elif (packet.src == "dnsServer" and packet.dst in {"facultyWS", "facultyPC", "labWS", "studentPC", "itWS", "itPC"}):
        accept()
      elif (packet.src == "guestPC" and packet.dst == "dnsServer"):
        accept()
      elif (packet.src == "dnsServer" and packet.dst == "guestPC"):
        accept()
      elif (packet.src == "trustedPC" and packet.dst in {"dnsServr", "studentPC"}):
        accept()
      elif (packet.src in {"dnsServer", "studentPC"} and packet.dst == "trustedpC"):
        accept()
      else:
        drop()
    else:
      drop()

  def _handle_PacketIn (self, event):
    """
    Handles packet in messages from the switch.
    """

    packet = event.parsed # This is the parsed packet data.
    if not packet.parsed:
      log.warning("Ignoring incomplete packet")
      return

    packet_in = event.ofp # The actual ofp_packet_in message.
    self.do_firewall(packet, packet_in, event.port)

def launch ():
  """
  Starts the components
  """
  def start_switch (event):
    log.debug("Controlling %s" % (event.connection,))
    Firewall(event.connection)
  core.openflow.addListenerByName("ConnectionUp", start_switch)