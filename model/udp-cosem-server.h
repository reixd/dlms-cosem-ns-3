/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
/*
 * udp-cosem-server.h
 * Implementation of the Class UdpCosemWrapperServer
 * Class that represents the UDP COSEM Wrapper transport sub-layer - Server side
 * Created on: 28-Sept-2012
 * Modified on:
 * Original author: JUANMALK
 */

#ifndef UDP_COSEM_SERVER_H
#define UDP_COSEM_SERVER_H

#include "ns3/object.h"
#include "ns3/simulator.h"

namespace ns3 {

class Socket;
class Packet;
class CosemAlServer;
class CosemApServer;

/** 
 * UDP COSEM Wrapper Transport sub-layer - Server
 *
 */

class UdpCosemWrapperServer : public Object
{
public:
  static TypeId GetTypeId (void);
  
  UdpCosemWrapperServer ();
 
  virtual ~UdpCosemWrapperServer ();

  // Recive ("read") the data from the socket and pass to the Cosem Application Layer
  void Recv (Ptr<Socket> socket);
	
  // Called when new packet is ready to be send
  void Send (Ptr<Packet> packet, Ptr<CosemApServer> cosemApServer);

  // Set & GET the pointer to a CosemAlServer object
  void SetCosemAlServer (Ptr<CosemAlServer> cosemAlServer);
  Ptr<CosemAlServer> GetCosemAlServer ();

  // Set & GET the pointer to a Socket object
  void SetSocket (Ptr<Socket> socket);
  Ptr<Socket> GetSocket ();

  // Assign a wPort number to the SAP created and attached to the SAL
  void SetwPortServer (Ptr<CosemApServer> cosemApServer);

  // Return the wPort number of the SAP connected to the SAL
  uint16_t GetwPortServer ();

  // Return the wPort number of the remote CAP
  uint16_t GetwPortClient ();

  // Set & GET the Udp Port listening by the SAL
  void SetUdpport (uint16_t udpPort);
  uint16_t GetUdpport ();

  // Set & GET the local Ip address (Sap)
  void SetLocalAddress (Address ip);
  Address GetLocalAddress ();

  // Set the remote ip address (Cap)
  void SetRemoteAddress (Address ip); 
  Address GetRemoteAddress ();


  // Type of services
  enum typeService { REQUEST, INDICATION, CONFIRM };
  
private:

  Ptr<Socket> m_socket;

  Ptr<CosemAlServer> m_cosemAlServer; 

  uint16_t m_wPortSap;  // Wrapper Port Number assigned to the SAP
  uint16_t m_wPortCap;  // Wrapper Port Number assigned to the remote CAP

  uint16_t m_udpPort;  // Udp port

  Address m_localAddress;  // Local Ip address 

  Address m_remoteAddress;  // Ip Address of the remote SAP

};

} // namespace ns3

#endif /* UDP_COSEM_SERVER_H */