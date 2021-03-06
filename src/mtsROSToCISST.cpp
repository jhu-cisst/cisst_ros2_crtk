/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*-    */
/* ex: set filetype=cpp softtabstop=4 shiftwidth=4 tabstop=4 cindent expandtab: */

/*
  Author(s):  Anton Deguet
  Created on: 2020-03-24

  (C) Copyright 2020-2022 Johns Hopkins University (JHU), All Rights Reserved.

--- begin cisst license - do not edit ---

This software is provided "as is" under an open source license, with
no warranty.  The complete license can be found in license.txt and
http://www.cisst.org/cisst/license.txt.

--- end cisst license ---

*/

#include <cisst_ros2_crtk/mtsROSToCISST.h>
#include <cisst_ros2_bridge/mtsROSToCISST.h>

void mtsROSToCISST(const crtk_msgs::msg::OperatingState & rosData,
                   prmOperatingState & cisstData,
                   std::shared_ptr<rclcpp::Node> node)
{
    mtsROSToCISSTHeader(rosData, cisstData, node);
    try {
        cisstData.State() = prmOperatingState::StateTypeFromString(rosData.state);
    } catch (...) {
        cisstData.State() = prmOperatingState::UNDEFINED;
    }
    cisstData.IsHomed() = rosData.is_homed;
    cisstData.IsBusy() = rosData.is_busy;
}

void mtsROSToCISST(const crtk_msgs::msg::StringStamped & rosData,
                   std::string & cisstData,
                   std::shared_ptr<rclcpp::Node>)
{
    cisstData = rosData.string;
}
