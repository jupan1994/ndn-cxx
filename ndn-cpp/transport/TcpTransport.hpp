/**
 * @author: Jeff Thompson
 * See COPYING for copyright and distribution information.
 */

#ifndef NDN_TCPTRANSPORT_HPP
#define	NDN_TCPTRANSPORT_HPP

#include "../c/transport/TcpTransport.h"
#include "../c/encoding/BinaryXMLElementReader.h"
#include "Transport.hpp"

namespace ndn {
  
class TcpTransport : public Transport {
public:
  TcpTransport() 
  {
    ndn_TcpTransport_init(&transport_);
    face_ = 0;
  }
  
  /**
   * 
   * @param face Not a shared_ptr because we assume that it will remain valid during the life of this Transport object.
   */
  virtual void connect(Face &face);
  
  virtual void send(const unsigned char *data, unsigned int dataLength);

  virtual void tempReceive();
  
private:
  struct ndn_TcpTransport transport_;
  Face *face_;
  // TODO: This belongs in the socket listener.
  ndn_BinaryXmlElementReader elementReader_;
};

}

#endif
