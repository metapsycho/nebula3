#ifndef PROPERTIES_TIMEPROPERTY_H
#define PROPERTIES_TIMEPROPERTY_H
//------------------------------------------------------------------------------
/**
    The time property adds the attribute "Time" to the entity. This 
    attributes contains the time since the time property has been
    attached to the entity.

    (C) 2007 Radon Labs GmbH
*/
#include "game/property.h"
#include "timing/time.h"

//------------------------------------------------------------------------------
namespace BaseGameFeature
{
class TimeProperty : public Game::Property
{
	DeclareClass(TimeProperty);
public:
    /// constructor
    TimeProperty();
    /// destructor
    virtual ~TimeProperty();
    /// setup callbacks for this property
    virtual void SetupCallbacks();
    /// setup default entity attributes
    virtual void SetupDefaultAttributes();
    /// called from Entity::ActivateProperties()
    virtual void OnActivate();
    /// called on begin of frame
    virtual void OnBeginFrame();

private:
    Timing::Time attachTime;
};
RegisterClass(TimeProperty);
}; // namespace Property
//------------------------------------------------------------------------------
#endif