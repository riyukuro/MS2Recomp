// entityactordata.h - member view of egfPhysX::EntityActorData (engine egfPhysX/EntityActorData.h), for units that hold
// efd::SmartPointer<egfPhysX::EntityActorData> without the PhysX SDK headers. NOT an original header. Only the two
// reference-count members the smart pointer calls: IncRefCount 0x140ae1dd0, DecRefCount 0x140ae1b60.
// Skipped when the real header came first; a unit must not include the real header after this one.
#pragma once
#ifndef EE_EGFPHYSX_ENTITYACTORDATA_H
namespace egfPhysX { class EntityActorData { public: void IncRefCount() const; void DecRefCount() const; }; }
#endif
