/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*-    */
/* ex: set filetype=cpp softtabstop=4 shiftwidth=4 tabstop=4 cindent expandtab: */

/*
  Author(s):  Anton Deguet
  Created on: 2020-03-24

  (C) Copyright 2020-2021 Johns Hopkins University (JHU), All Rights Reserved.

--- begin cisst license - do not edit ---

This software is provided "as is" under an open source license, with
no warranty.  The complete license can be found in license.txt and
http://www.cisst.org/cisst/license.txt.

--- end cisst license ---

*/

#ifndef _mtsCISSTToROS_CRTK_h
#define _mtsCISSTToROS_CRTK_h

// cisst include
#include <cisstParameterTypes/prmOperatingState.h>

// crtk
#include <crtk_msgs/msg/operating_state.hpp>
#include <crtk_msgs/msg/string_stamped.hpp>
#include <crtk_msgs/srv/trigger_operating_state.hpp>

// crtk_msgs
bool mtsCISSTToROS(const prmOperatingState & cisstData,
                   crtk_msgs::msg::OperatingState & rosData,
                   const std::string & debugInfo);

bool mtsCISSTToROS(const std::string & cisstData,
                   crtk_msgs::msg::StringStamped & rosData,
                   const std::string & debugInfo);

// crtk_srvs
bool mtsCISSTToROS(const prmOperatingState & cisstData,
                   crtk_msgs::srv::TriggerOperatingState::Response & rosData,
                   const std::string & debugInfo);

#endif // _mtsCISSTToROS_CRTK_h
