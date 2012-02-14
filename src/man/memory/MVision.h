/**
 * MVision.hpp
 *
 * @class MVision : this is the memory object representation of vision
 *
 */

#pragma once

#include <boost/shared_ptr.hpp>

#include "protos/Vision.pb.h"
#include "MObject.h"
#include "vision/Vision.h"
#include "ClassHelper.h"

namespace man {
namespace memory {
class MVision: public Message {

    ADD_SHARED_PTR(MVision);

public:
    static const MObject_ID id = MVISION_ID;

public:
    MVision(boost::shared_ptr<Vision> vision);
    virtual ~MVision();

    /**
     * Updates all the fields of the underlying proto::PVision with values
     * from the Vision object
     */
    void updateData();

private:
    //update helper methods
    void update(proto::PVision::PVisualDetection* visual_detection,
            VisualDetection* visualDetection);

private:
    boost::shared_ptr<Vision> vision;
    boost::shared_ptr<proto::PVision> data;

};
}
}
