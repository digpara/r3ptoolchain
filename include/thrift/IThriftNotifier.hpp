/*
 * IThriftNotifier.hpp
 *
 *  Created on: 2014年4月19日
 *      Author: chengliang
 */

#ifndef ITHRIFTNOTIFIER_HPP_
#define ITHRIFTNOTIFIER_HPP_

#include <string>

class IThriftNotifier {
public:
  IThriftNotifier() {
  }

  virtual ~IThriftNotifier() {
  }

  virtual std::string notify(const std::string & para) = 0;
};
#endif /* ITHRIFTNOTIFIER_HPP_ */
