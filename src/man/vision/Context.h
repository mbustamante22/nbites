// This file is part of Man, a robotic perception, locomotion, and
// team strategy application created by the Northern Bites RoboCup
// team of Bowdoin College in Brunswick, Maine, for the Aldebaran
// Nao robot.
//
// Man is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// Man is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser Public License for more details.
//
// You should have received a copy of the GNU General Public License
// and the GNU Lesser Public License along with Man.  If not, see
// <http://www.gnu.org/licenses/>.


#ifndef Context_h_DEFINED
#define Context_h_DEFINED

#include <stdlib.h>

#include "Common.h"
#include "VisionStructs.h"
#include "VisionHelpers.h"

class Context; // forward reference
#include "ObjectFragments.h"
#include "Threshold.h"
#include "VisualFieldObject.h"
#include "ConcreteFieldObject.h"
#include "VisualCorner.h"
#include "ConcreteCorner.h"
#include "ConcreteLine.h"
#include "VisualBall.h"
#include "Vision.h"
#include "Field.h"


class Context {
public:
    Context(Vision* vis, Threshold* thr, Field* fie);
    virtual ~Context() {}

    void init();
    void setContext();

    // setters
    void setTCorner() {tCorner++;}
    void setLCorner() {lCorner++;}
    void setOLCorner() {oCorner++; lCorner++;}
    void setILCorner() {iCorner++; lCorner++;}
    void setRightYellowPost() {rightYellowPost = true; yellowPost = true;}
    void setLeftYellowPost() {leftYellowPost = true; yellowPost = true;}
    void setUnknownYellowPost() {unknownYellowPost = true; yellowPost = true;}
    void setRightBluePost() {rightBluePost = true; bluePost = true;}
    void setLeftBluePost() {leftBluePost = true; bluePost = true;}
    void setUknownBluePost() {unknownBluePost = true; bluePost = true;}
    void setUnknownCross() {unknownCross = true; cross = true;}
    void setYellowCross() {yellowCross = true; cross = true;}
    void setBlueCross() {blueCross = true; cross = true;}
    void setCross() {cross = true;}
    void setBall() {ball = true;}
    void setGoalBoxLines() {seeGoalBoxLines = true; cout << "See goal box lines" << endl;}

    // getters
    int  getTCorner() {return tCorner;}
    int  getLCorner() {return lCorner;}
    int  getILCorner() {return iCorner;}
    int  getOLCorner() {return oCorner;}
    bool getRightYellowPost() {return rightYellowPost;}
    bool getLeftYellowPost() {return leftYellowPost;}
    bool getUnknownYellowPost() {return unknownYellowPost;}
    bool getYellowPost() {return yellowPost;}
    bool getRightBluePost() {return rightBluePost;}
    bool getLeftBluePost() {return leftBluePost;}
    bool getUnknownBluePost() {return unknownBluePost;}
    bool getCross() {return cross;}
    bool getUnknownCross() {return unknownCross;}
    bool getYellowCross() {return yellowCross;}
    bool getBlueCross() {return blueCross;}
    bool getBall() {return ball;}
    bool getGoalBoxLines() {return seeGoalBoxLines;}

    // other
    // Given a list of VisualCorners, attempts to assign ConcreteCorners
    // (ideally one, but sometimes multiple) that correspond with where the
    // corner could possibly be on the field.  For instance, if we have a T
    // corner and it is right next to the blue goal left post, then it is the
    // blue goal right T. Modifies the corners passed in by calling the
    // setPossibleCorners method; in certain cases the shape of a corner might
    // be switched too (if an L corner is determined to be a T instead, its
    // shape is changed accordingly).
    void identifyCorners(std::list<VisualCorner> &corners);

    void findCornerRelationship(VisualCorner & first, VisualCorner & second);

    const list<const ConcreteCorner*> classifyCornerWithObjects(
        const VisualCorner &corner,
        const std::vector <const VisualFieldObject*> &visibleObjects) const;

    std::list<const ConcreteCorner*>
    compareObjsCorners(const VisualCorner& corner,
                       const std::vector<const ConcreteCorner*>& possibleCorners,
                       const std::vector<const VisualFieldObject*>& visibleObjects)
        const;

    const bool arePointsCloseEnough(const float estimatedDistance,
                                    const ConcreteCorner* j,
                                    const VisualFieldObject* k,
                                    const float distToCorner, int n) const;


    float getAllowedDistanceError(const VisualFieldObject* obj) const;
    // Given two points on the screen, estimates the straight line distance
    // between them, on the field
    float getEstimatedDistance(const point<int> &point1,
                               const point<int> &point2) const;

    // Estimates the distance between the corner and the object based on
    // vectors
    float getEstimatedDistance(const VisualCorner *c,
                               const VisualFieldObject *obj) const;

    float getEstimatedDistance(float dist1, float bearing1,
                               float dist2, float bearing2) const;

    float getEstimatedDistance(const VisualCorner& corner,
                               const point<int>& p) const;
    // Uses the actual objects' locations on the field to calculate straight
    // line distance
    float getRealDistance(const ConcreteCorner *c,
                          const VisualFieldObject *obj, int w) const;
    // Helper method that iterates over a list of ConcreteCorner pointers and
    // prints their string representations
    void printPossibilities(const std::list <const ConcreteCorner*> &list)const;
    // Determines which field objects are visible on the screen and returns
    // a vector of the pointers of the objects that are visible.
    std::vector<const VisualFieldObject*> getVisibleFieldObjects() const;

    vector<const VisualFieldObject*> getAllVisibleFieldObjects() const;

    const bool goalSuitableForPixEstimate(const VisualFieldObject * goal) const;


private:
    Vision* vision;
    Threshold* thresh;
    Field* field;

    static const int NUM_FIELD_OBJECTS_WITH_DIST_INFO = 4;
    VisualFieldObject const * allFieldObjects[NUM_FIELD_OBJECTS_WITH_DIST_INFO];

    bool rightYellowPost;
    bool leftYellowPost;
    bool unknownYellowPost;
    bool yellowPost;
    bool rightBluePost;
    bool leftBluePost;
    bool unknownBluePost;
    bool bluePost;
    int  tCorner;
    int  lCorner;
    int  iCorner;
    int  oCorner;
    bool cross;
    bool unknownCross;
    bool yellowCross;
    bool blueCross;
    bool ball;
    bool seeGoalBoxLines;
    bool debugIdentifyCorners;
};

#endif // Context_h_DEFINED
