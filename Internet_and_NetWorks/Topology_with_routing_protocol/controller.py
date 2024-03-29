# Lab5 Skeleton

from pox.core import core
from pox.lib import util
import pox.openflow.libopenflow_01 as of

log = core.getLogger()

class Routing (object):
    
  def __init__ (self, connection):
    # Keep track of the connection to the switch so that we can
    # send it messages!
    self.connection = connection

    # This binds our PacketIn event listener
    connection.addListeners(self)
  
  def accept(self, packet, packet_in, port_num):
    msg = of.ofp_flow_mod()
    msg.match = of.ofp_match.from_packet(packet)
    msg.idle_timeout = 30
    msg.hard_timeout = 40
    msg.actions.append(of.ofp_actions_output(port=port_num))
    msg.data = packet_in
    self.connection.send(msg)

  def drop(self, packet, packet_in):
    msg = of.ofp_flow_mod()
    msg.match = of.ofp_match().from_packet(packet)
    msg.idle_timeout = 30
    msg.hard_time = 40
    msg.buffer_id = packet_in.buffer_id
    self.connection.send(msg)

  def do_routing (self, packet, packet_in, port_on_switch, switch_id):
    # port_on_swtich - the port on which this packet was received
    # switch_id - the switch which received this packet

    # Your code here
    
    arp = packet.find('arp')
    tcp = packet.find('tcp')
    icmp = packet.find('icmp')
    ipv4 = packet.find('ipv4')
    udp = packet.find('udp')

    student_sub = {'studentPC':'10.0.2.2', 'labWS':'10.0.2.3'}
    it_sub = {'itWS':'10.0.3.2', 'itPC':'10.0.3.3'}
    dc_sub = {'dnsServer':'10.0.100.4', 'webServer':'10.0.100.3', 'examServer':'10.0.100.2'}
    faculty_sub = {'facultyWS':'10.0.1.2', 'printer':'10.0.1.3', 'facultyPC':'10.0.1.4'}
    internet_sub = {'trustedPC':'200.20.203.2', 'guestPC':'200.20.198.2'}

    # Rule 1: ICMP only between Student LAN, Faculty LAN, IT LAN, and same subnet
    if icmp is not None:
      # Core Switch
      if switch_id == 1:
        if str(ipv4.srcip) in student_sub.values() and str(ipv4.dstip) in it_sub.values():
          self.accept(packet, packet_in, 4)
        if str(ipv4.srcip) in student_sub.values() and str(ipv4.dstip) in faculty_sub.values():
          self.accept(packet, packet_in, 2)
        if str(ipv4.srcip) in it_sub.values() and str(ipv4.dstip) in faculty_sub.values():
          self.accept(packet, packet_in, 2)
        if str(ipv4.srcip) in it_sub.values() and str(ipv4.dstip) in student_sub.values():
          self.accept(packet, packet_in, 3)
        if str(ipv4.srcip) in faculty_sub.values() and str(ipv4.dstip) in it_sub.values():
          self.accept(packet, packet_in, 4)
        if str(ipv4.srcip) in faculty_sub.values() and str(ipv4.dstip) in student_sub.values():
          self.accept(packet, packet_in, 3)
        if str(ipv4.srcip) in internet_sub.values() and str(ipv4.dstip) in internet_sub.values():
          if str(ipv4.srcip) == '200.20.203.2' and str(ipv4.dstip) == '200.20.198.2':
            self.accept(packet, packet_in, 7)
          if str(ipv4.srcip) == '200.20.198.2' and str(ipv4.dstip) == '200.20.203.2':
            self.accept(packet, packet_in, 6)
      
      # Faculty Switch
      elif switch_id == 2:
        if str(ipv4.dstip) in faculty_sub.values():
          if str(ipv4.dstip) == '10.0.1.2':
            self.accept(packet, packet_in, 2)
          if str(ipv4.dstip) == '10.0.1.3':
            self.accept(packet, packet_in, 3)
          if str(ipv4.dstip) == '10.0.1.4':
            self.accept(packet, packet_in, 4)

      # Student LAN Switch
      elif switch_id == 3:
        if str(ipv4.dstip) in student_sub.values():
          if str(ipv4.dstip) == '10.0.2.2':
            self.accept(packet, packet_in, 2)
          if str(ipv4.dstip) == '10.0.2.3':
            self.accept(packet, packet_in, 3)
      
      # IT Switch
      elif switch_id == 4:
        if str(ipv4.dstip) in it_sub.values():
          if str(ipv4.dstip) == '10.0.3.2':
            self.accept(packet, packet_in, 2)
          if str(ipv4.dstip) == '10.0.3.3':
            self.accept(packet, packet_in, 3)

      # University Datacenter Switch
      elif switch_id == 5:
        if str(ipv4.dstip) in dc_sub.values():
          if str(ipv4.dstip) == '10.0.100.2':
            self.accept(packet, packet_in, 2)
          if str(ipv4.dstip) == '10.0.100.3':
            self.accept(packet, packet_in, 3)
          if str(ipv4.dstip) == '10.0.100.4':
            self.accept(packet, packet_in, 4)
    
    # Rule 2: TCP Traffic Between the Data Center subnet, IT subnet, Student subnet, Faculty subnet and trusted PC
    # And devices on the same subnet
    elif tcp is not None:
      # Core Switch
      if switch_id == 1:
        if str(ipv4.srcip) in student_sub.values() and str(ipv4.dstip) in it_sub.values():
          self.accept(packet, packet_in, 4)
        if str(ipv4.srcip) in student_sub.values() and str(ipv4.dstip) in faculty_sub.values():
          self.accept(packet, packet_in, 2)
        if str(ipv4.srcip) in student_sub.values() and str(ipv4.dstip) in dc_sub.values():
          if str(ipv4.dst) != '10.0.100.2':
            self.accept(packet, packet_in, 5)
        if str(ipv4.srcip) in student_sub.values() and str(ipv4.dstip) in internet_sub.values():
          if str(ipv4.dstip) == '200.20.203.2': 
            self.accept(packet, packet_in, 6)

        if str(ipv4.srcip) in it_sub.values() and str(ipv4.dstip) in faculty_sub.values():
          self.accept(packet, packet_in, 2)
        if str(ipv4.srcip) in it_sub.values() and str(ipv4.dstip) in student_sub.values():
          self.accept(packet, packet_in, 3)
        if str(ipv4.srcip) in it_sub.values() and str(ipv4.dstip) in dc_sub.values():
          if str(ipv4.dst) != '10.0.100.2':
            self.accept(packet, packet_in, 5)
        if str(ipv4.srcip) in it_sub.values() and str(ipv4.dstip) in internet_sub.values():
          if str(ipv4.dstip) == '200.20.203.2':
            self.accept(packet, packet_in, 6)

        if str(ipv4.srcip) in faculty_sub.values() and str(ipv4.dstip) in it_sub.values():
          self.accept(packet, packet_in, 4)
        if str(ipv4.srcip) in faculty_sub.values() and str(ipv4.dstip) in student_sub.values():
          self.accept(packet, packet_in, 3)
        if str(ipv4.srcip) in faculty_sub.values() and str(ipv4.dstip) in dc_sub.values():
          self.accept(packet, packet_in, 5)
        if str(ipv4.srcip) in faculty_sub.values() and str(ipv4.dstip) in internet_sub.values():
          if str(ipv4.dstip) == '200.20.203.2':
            self.accept(packet, packet_in, 6)

        if str(ipv4.srcip) in dc_sub.values() and str(ipv4.dstip) in it_sub.values():
          self.accept(packet, packet_in, 4)
        if str(ipv4.srcip) in dc_sub.values() and str(ipv4.dstip) in student_sub.values():
          self.accept(packet, packet_in, 3)
        if str(ipv4.srcip) in dc_sub.values() and str(ipv4.dstip) in faculty_sub.values():
          self.accept(packet, packet_in, 2)
        if str(ipv4.srcip) in dc_sub.values() and str(ipv4.dstip) in internet_sub.values():
          if str(ipv4.dstip) == '200.20.203.2':
            self.accept(packet, packet_in, 6)

        if str(ipv4.srcip) in internet_sub.values() and str(ipv4.dstip) in it_sub.values():
          if str(ipv4.srcip) == '200.20.203.2':
            self.accept(packet, packet_in, 4)
        if str(ipv4.srcip) in internet_sub.values() and str(ipv4.dstip) in student_sub.values():
          if str(ipv4.srcip) == '200.20.203.2':
            self.accept(packet, packet_in, 3)
        if str(ipv4.srcip) in internet_sub.values() and str(ipv4.dstip) in dc_sub.values():
          if str(ipv4.srcip) == '200.20.203.2' and str(ipv4.dstip) != '10.0.100.2':
            self.accept(packet, packet_in, 5)
        if str(ipv4.srcip) in internet_sub.values() and str(ipv4.dstip) in faculty_sub.values():
          if str(ipv4.srcip) == '200.20.203.2':
            self.accept(packet, packet_in, 6)

        if str(ipv4.srcip) == '200.20.203.2' and str(ipv4.dstip) == '200.20.198.2':
          self.accept(packet, packet_in, 7)
        if str(ipv4.srcip) == '200.20.198.2' and str(ipv4.dstip) == '200.20.203.2':
          self.accept(packet, packet_in, 6)
      
      # Faculty Switch
      if switch_id == 2:
        if str(ipv4.dstip) in faculty_sub.values():
          if str(ipv4.dstip) == '10.0.1.2':
            self.accept(packet, packet_in, 2)
          if str(ipv4.dstip) == '10.0.1.3':
            self.accept(packet, packet_in, 3)
          if str(ipv4.dstip) == '10.0.1.4':
            self.accept(packet, packet_in, 4)

      # Student LAN Switch
      if switch_id == 3:
        if str(ipv4.dstip) in student_sub.values():
          if str(ipv4.dstip) == '10.0.2.2':
            self.accept(packet, packet_in, 2)
          if str(ipv4.dstip) == '10.0.2.3':
            self.accept(packet, packet_in, 3)
      
      # IT Switch
      if switch_id == 4:
        if str(ipv4.dstip) in it_sub.values():
          if str(ipv4.dstip) == '10.0.3.2':
            self.accept(packet, packet_in, 2)
          if str(ipv4.dstip) == '10.0.3.3':
            self.accept(packet, packet_in, 3)

      # University Datacenter Switch
      if switch_id == 2:
        if str(ipv4.dstip) in dc_sub.values():
          if str(ipv4.dstip) == '10.0.100.2' and str(ipv4.srcip) in faculty_sub.values():
            self.accept(packet, packet_in, 2)
          if str(ipv4.dstip) == '10.0.100.3':
            self.accept(packet, packet_in, 3)
          if str(ipv4.dstip) == '10.0.100.4':
            self.accept(packet, packet_in, 4)
    



    # Rule 3: UDP messags between Student subnet, IT subnet, Faculty subnet, and Data Center,
    # and devices on the same subnet
    if udp is not None:
      # Core Switch
      if switch_id == 1:
        if str(ipv4.srcip) in student_sub.values() and str(ipv4.dstip) in it_sub.values():
          self.accept(packet, packet_in, 4)
        if str(ipv4.srcip) in student_sub.values() and str(ipv4.dstip) in faculty_sub.values():
          self.accept(packet, packet_in, 2)
        if str(ipv4.srcip) in student_sub.values() and str(ipv4.dstip) in dc_sub.values():
          self.accept(packet, packet_in, 5)
        if str(ipv4.srcip) in it_sub.values() and str(ipv4.dstip) in faculty_sub.values():
          self.accept(packet, packet_in, 2)
        if str(ipv4.srcip) in it_sub.values() and str(ipv4.dstip) in student_sub.values():
          self.accept(packet, packet_in, 3)
        if str(ipv4.srcip) in it_sub.values() and str(ipv4.dstip) in dc_sub.values():
          self.accept(packet, packet_in, 5)
        if str(ipv4.srcip) in faculty_sub.values() and str(ipv4.dstip) in it_sub.values():
          self.accept(packet, packet_in, 4)
        if str(ipv4.srcip) in faculty_sub.values() and str(ipv4.dstip) in student_sub.values():
          self.accept(packet, packet_in, 3)
        if str(ipv4.srcip) in faculty_sub.values() and str(ipv4.dstip) in dc_sub.values():
          self.accept(packet, packet_in, 5)
        if str(ipv4.srcip) in internet_sub.values() and str(ipv4.dstip) in internet_sub.values():
          if str(ipv4.srcip) == '200.20.203.2' and str(ipv4.dstip) == '200.20.198.2':
            self.accept(packet, packet_in, 7)
          if str(ipv4.srcip) == '200.20.198.2' and str(ipv4.dstip) == '200.20.203.2':
            self.accept(packet, packet_in, 6)
      
      # Faculty Switch
      if switch_id == 2:
        if str(ipv4.dstip) in faculty_sub.values():
          if str(ipv4.dstip) == '10.0.1.2':
            self.accept(packet, packet_in, 2)
          if str(ipv4.dstip) == '10.0.1.3':
            self.accept(packet, packet_in, 3)
          if str(ipv4.dstip) == '10.0.1.4':
            self.accept(packet, packet_in, 4)

      # Student LAN Switch
      if switch_id == 3:
        if str(ipv4.dstip) in student_sub.values():
          if str(ipv4.dstip) == '10.0.2.2':
            self.accept(packet, packet_in, 2)
          if str(ipv4.dstip) == '10.0.2.3':
            self.accept(packet, packet_in, 3)
      
      # IT Switch
      if switch_id == 4:
        if str(ipv4.dstip) in it_sub.values():
          if str(ipv4.dstip) == '10.0.3.2':
            self.accept(packet, packet_in, 2)
          if str(ipv4.dstip) == '10.0.3.3':
            self.accept(packet, packet_in, 3)

      # University Datacenter Switch
      if switch_id == 2:
        if str(ipv4.dstip) in dc_sub.values():
          if str(ipv4.dstip) == '10.0.100.2':
            self.accept(packet, packet_in, 2)
          if str(ipv4.dstip) == '10.0.100.3':
            self.accept(packet, packet_in, 3)
          if str(ipv4.dstip) == '10.0.100.4':
            self.accept(packet, packet_in, 4)

    self.drop(packet, packet_in)



    

  def _handle_PacketIn (self, event):
    """
    Handles packet in messages from the switch.
    """
    packet = event.parsed # This is the parsed packet data.
    if not packet.parsed:
      log.warning("Ignoring incomplete packet")
      return

    packet_in = event.ofp # The actual ofp_packet_in message.
    self.do_routing(packet, packet_in, event.port, event.dpid)

def launch ():
  """
  Starts the component
  """
  def start_switch (event):
    log.debug("Controlling %s" % (event.connection,))
    Routing(event.connection)
  core.openflow.addListenerByName("ConnectionUp", start_switch)
