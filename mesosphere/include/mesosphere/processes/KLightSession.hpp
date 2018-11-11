#pragma once

#include <mesosphere/core/util.hpp>
#include <mesosphere/core/Result.hpp>
#include <mesosphere/interfaces/IClientServerParent.hpp>
#include <mesosphere/interfaces/ISetAllocated.hpp>
#include <mesosphere/interfaces/ILimitedResource.hpp>
#include <mesosphere/processes/KLightClientSession.hpp>
#include <mesosphere/processes/KLightServerSession.hpp>

namespace mesosphere
{

class KLightSession final :
    public KAutoObject,
    public ISetAllocated<KLightSession>,
    public ILimitedResource<KLightSession>,
    public IClientServerParent<KLightSession, KLightClientSession, KLightServerSession> {

    public:
    MESOSPHERE_AUTO_OBJECT_TRAITS(AutoObject, LightSession);
    MESOSPHERE_LIMITED_RESOURCE_TRAITS(10s);

    virtual ~KLightSession();

    Result Initialize();
};

MESOSPHERE_AUTO_OBJECT_DEFINE_INCREF(LightSession);

}
