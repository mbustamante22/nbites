from .. import NogginConstants
SUPER_SAFE_KICKS = False # Only kick straight when we see the goal
MAX_FORWARD_KICK_ANGLE = 55
MIN_SIDEWASE_KICK_ANGLE = 15
DEBUG_KICKS = False
ALIGN_FOR_KICK = True

KICK_STRAIGHT_BEARING_THRESH = 20
ALIGN_FOR_KICK_BEARING_THRESH = 60
ALIGN_FOR_KICK_GAIN = 2.0

(LEFT_FOOT,
 RIGHT_FOOT,
 MID_LEFT,
 MID_RIGHT,
 INCORRECT_POS ) = range(5)


SIDE_STEP_MIN_SPEED = -4.0
SIDE_STEP_MAX_SPEED = 4.0
SIDE_STEP_MIN_MAGNITUDE = 2.0

LEFT_FOOT_CENTER_Y = 7
RIGHT_FOOT_CENTER_Y = -7
LEFT_FOOT_L_Y = 8
LEFT_FOOT_R_Y = 3
RIGHT_FOOT_L_Y = -LEFT_FOOT_R_Y
RIGHT_FOOT_R_Y = -LEFT_FOOT_L_Y

MAX_KICK_X = 22
MIN_KICK_X = 0

ACROSS_GOAL_BEARING_THRESH = 60
OUT_OF_GOAL_BEARING_THRESH = -10

# Kick objectives
NUM_OBJECTIVES = 5
(OBJECTIVE_CLEAR,
 OBJECTIVE_CENTER,
 OBJECTIVE_SHOOT_CLOSE,
 OBJECTIVE_SHOOT_FAR,
 OBJECTIVE_UNCLEAR) = range(NUM_OBJECTIVES)

# inOppCorner constants
TOP_OPP_CORNER_SLOPE = -1
BOTTOM_OPP_CORNER_SLOPE = 1

OPP_CORNER_LEFT_X = NogginConstants.FIELD_WIDTH - 100.
TOP_OPP_CORNER_Y = NogginConstants.FIELD_HEIGHT

# Penalty Kick
ALIGN_FOR_KICK_MIN_ANGLE = 10

LOOK_POST_KICK_FRAMES_OFF = 10

# clearBall constants
CLEAR_CENTER_FIELD_STRAIGHT_ANGLE = 60
FACING_SIDELINE_ANGLE = 30

SHOOT_AT_LEFT_AIM_POINT = (NogginConstants.LANDMARK_OPP_GOAL_LEFT_POST_X,
                            NogginConstants.LANDMARK_OPP_GOAL_RIGHT_POST_Y +
                            NogginConstants.GOAL_WIDTH *3.0/4.0)


SHOOT_AT_RIGHT_AIM_POINT = ( NogginConstants.LANDMARK_OPP_GOAL_LEFT_POST_X,
                              NogginConstants.LANDMARK_OPP_GOAL_RIGHT_POST_Y +
                              NogginConstants.GOAL_WIDTH/4.0)


SHOOT_BALL_LOC_ALIGN_ANGLE = 10
SHOOT_BALL_SIDE_KICK_ANGLE = 45

SHOOT_BALL_FAR_LOC_ALIGN_ANGLE = 25
SHOOT_BALL_FAR_SIDE_KICK_ANGLE = 50
