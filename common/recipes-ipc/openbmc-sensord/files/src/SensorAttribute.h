/*
 * Copyright 2014-present Facebook. All Rights Reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#pragma once
#include <string>
#include <object-tree/Attribute.h>

namespace openbmc {
namespace ipc {

/**
 * Attribute for sensor.
 */
class SensorAttribute : public Attribute {
  private:
    std::string addr_{""}; // address to be accessed through SensorApi

  public:
    using Attribute::Attribute; // inherit constructor

    void setAddr(const std::string &addr) {
      addr_ = addr;
    }

    const std::string& getAddr() const {
      return addr_;
    }

    /**
     * Setting addr_ to an non-empty string will make the sensor attribute
     * accessible through SensorApi.
     *
     * @return is accessibile through SensorApi
     */
    bool isAccessible() const {
      return addr_.compare("") != 0;
    }
};

} // namespace ipc
} // namespace openbmc
