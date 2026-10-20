// PhysX 2.8.4.6 overlay (see NxScene.h here): the stock NxPhysics.h includes "NxScene.h" from its own directory, which would
// bypass the overlay, so the fixed NxScene is declared first and the stock include then hits its guard.
#ifndef MS2_PHYSX2846_NXPHYSICS_H
#define MS2_PHYSX2846_NXPHYSICS_H

#include "NxScene.h"
#include <Physics/include/NxPhysics.h>

#endif
