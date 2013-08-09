/**
 * @author: Jeff Thompson
 * See COPYING for copyright and distribution information.
 */

#ifndef NDN_KEY_CHAIN_HPP
#define	NDN_KEY_CHAIN_HPP

#include "data.hpp";

namespace ndn {

class KeyChain {
public:
  /**
   * In data, set the signed info key to the default public key and set the signature using the default private key.
   * @param data The Data object to sign and set the signature.
   */
  static void defaultSign(Data &data);

};

}

#endif
