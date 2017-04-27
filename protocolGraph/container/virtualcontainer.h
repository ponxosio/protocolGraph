#ifndef VIRTUALCONTAINER_H
#define VIRTUALCONTAINER_H

#include <utils/units.h>

class VirtualContainer
{
public:
    typedef enum {
        tube,
        gel,
        petri_dish,
        well
    } ContainerType;

    VirtualContainer(const std::string & name, ContainerType vcType, units::Volume capacity, units::Volume initialVolume, units::Temperature storeTemperature) :
        name(name)
    {
        this->capacity = capacity;
        this->initialVolume = initialVolume;
        this->storeTemperature = storeTemperature;
        this->vcType = vcType;
    }
    virtual ~VirtualContainer() {}

    inline const std::string & getName() const {
        return name;
    }

    inline const units::Volume & getInitialVolume() const {
        return initialVolume;
    }

    inline const units::Volume & getCapacity() const {
        return capacity;
    }

    inline const units::Temperature & getStoreTemperature() const {
        return storeTemperature;
    }

    inline const ContainerType getVcType() const {
        return vcType;
    }

protected:
    std::string name;
    units::Volume capacity;
    units::Volume initialVolume;
    units::Temperature storeTemperature;
    ContainerType vcType;
};

#endif // VIRTUALCONTAINER_H
