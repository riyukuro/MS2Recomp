#pragma once
// egf::ScriptContext, the class of the global egf::g_bapiContext (0x143b059e8; was the Unk_EntityAppFramework views).
// Lean copy of the SDK class (GameFramework/egf/ScriptContext.h): the real header pulls in egf/Entity.h, whose
// header statics (kCID_INVALID, kENTITY_INVALID, kEVT_INVALID) shift a unit's dynamic initializers. It defines the
// SDK include guard, so include <egf/ScriptContext.h> before this header where a unit needs the whole class.
#include <efd/SmartPointer.h>
#ifndef EE_ScriptContext_h
#define EE_ScriptContext_h
namespace efd { class ServiceManager; }
namespace egf
{
class ScriptContext
{
public:
    // The SDK inline: m_spManager->GetSystemServiceAs<T>() (EE_ASSERT(m_spManager) compiles to nothing).
    // efd::SmartPointer<const efd::ServiceManager>::operator-> is 0x1401cd190, called only by these getters.
    template <typename T> T* GetSystemServiceAs() const { return m_spManager->GetSystemServiceAs<T>(); }

protected:
    efd::SmartPointer<const efd::ServiceManager> m_spManager;   // +0x00
    void* m_pBehaviorStack;                                     // +0x08 efd::stack<egf::PendingBehaviorPtr>*
    bool m_bImmediateStack;                                     // +0x10
};
extern ScriptContext g_bapiContext;
}
#endif

// The out-of-line instantiations that units call without seeing the service class: declared here, each defined once
// by the unit the exe places it in. The ecr service getters (0x1410a68f0 SceneGraphService, ...) use the template:
// the stock bapiCoreRuntime instantiates them too, so their definers make them inline (COMDAT) specializations.
class CubeMapInformationService;
class Unk_AlphaService;
class Unk_HwService;
class MS2SceneGraphService;
namespace ecr { class RenderService; }
template <> CubeMapInformationService* egf::ScriptContext::GetSystemServiceAs<CubeMapInformationService>() const;   // 0x1401cd040 (buddy)
template <> Unk_AlphaService* egf::ScriptContext::GetSystemServiceAs<Unk_AlphaService>() const;                     // 0x14098c540 (alphaanimation)
template <> Unk_HwService* egf::ScriptContext::GetSystemServiceAs<Unk_HwService>() const;                           // 0x14098c5b0 (alphaanimation)
template <> MS2SceneGraphService* egf::ScriptContext::GetSystemServiceAs<MS2SceneGraphService>() const;               // 0x1409a5700 (applyeffect)
template <> ecr::RenderService* egf::ScriptContext::GetSystemServiceAs<ecr::RenderService>() const;                 // 0x14127bf80 (gfxmoviebackground)
