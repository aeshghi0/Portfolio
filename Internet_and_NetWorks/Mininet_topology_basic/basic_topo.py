##!/usr/bin/python
#from mininet.topo import Topo
#from mininet.net import Mininet
#from mininet.cli import CLI
#from mininet.link import TCLink
#
#class MyTopology(Topo):
#    """
#    A basic topology
#    """
#    def __init__(self):
#        Topo.__init__(self)
#        # Set Up Topology Here
#        switch = self.addSwitch('s1') ## Adds a Switch
#        host1 = self.addHost('h1') ## Adds a Host
#        self.addLink(host1, switch) ## Add a link
#        host2 = self.addHost('h2') ## Adds a Host
#        self.addLink(host2, switch)
#if __name__ == '__main__':
#    """
#    If this script is run as an executable (by chmod +x), this is
#    what it will do
#    """
#    topo = MyTopology() ## Creates the topology
#    net = Mininet(topo=topo, link=TCLink) ## Loads the topology
#    net.start() ## Starts Mininet
#    # Commands here will run on the simulated topology
#    CLI(net)
#    net.stop() ## Stops Mininet
#

from mininet.topo import Topo
from mininet.net import Mininet
from mininet.cli import CLI
from mininet.link import TCLink

class MyTopology(Topo):
    """
    # A basic topology
    """
    def __init__(self):
        Topo.__init__(self)
        # Set up Topology here
        switch1 = self.addSwitch('switch1') # Add a switch
        switch2 = self.addSwitch('switch2') # Add a switch
        switch3 = self.addSwitch('switch3') # Add a switch
        switch4 = self.addSwitch('switch4') # Add a switch

        siri = self.addHost('Siri') # Add a host
        desktop = self.addHost('Desktop') # Add a host
        alexa = self.addHost('Alexa') # Add a host
        fridge = self.addHost('Fridge') # Add a host
        tv = self.addHost('SmartTV') # Add a host
        server = self.addHost('Server') # Add a host

        self.addLink(siri, switch1) # Add a link
        self.addLink(desktop, switch2) # Add a link
        self.addLink(fridge, switch2) # Add a link
        self.addLink(alexa, switch3) # Add a link
        self.addLink(tv, switch3) # Add a link
if __name__ == '__main__':
    """
    If this script is run as an executable (by chmod +x), this is
    what it will do
    """
    topo = MyTopology() ## Creates the topology
    net = Mininet(topo=topo, link=TCLink) ## Loads the topology
    net.start() ## Starts Mininet
    # Commands here will run on the simulated topology
    CLI(net)
    net.stop() ## Stops Mininet
