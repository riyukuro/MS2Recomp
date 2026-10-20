// physxpropservice.h - ecrPhysX::PropService declaration only (not an original header). The real
// GameFramework/ecrPhysX/PropService.h includes the PhysX SDK headers, which are not on the include path. Same class id
// (efd::kCLASSID_PhysXPropService 0x07002020, for IDependencyRegistrar::AddDependency<ecrPhysX::PropService>); the
// members the game calls are bound by mangled name through progress/symbols-engine.tsv.
#pragma once
#include <efd/IDs.h>
#include <efd/utf8string.h>
#include <ecr/ecrSystemServiceIDs.h>

namespace ecrPhysX
{
class PropService
{
public:
    static const efd::ClassID CLASS_ID = efd::kCLASSID_PhysXPropService;
    void SetDebugRender(const efd::utf8string& sceneName, bool bActive);
};
}
