#ifndef VARIABLESTATE_H
#define VARIABLESTATE_H

class VariableState
{
public:
    VariableState(){
        value = 0.0;
        isPhysical = false;
        isWritable = true;
        hasBeenWritten = false;
    }

    VariableState(const VariableState & var) {
        value = var.value;
        isPhysical = var.isPhysical;
        isWritable = var.isWritable;
        hasBeenWritten = var.hasBeenWritten;
    }

    virtual ~VariableState(){}

    inline double getValue() const  {
        return value;
    }

    inline bool getIsPhysical() const {
        return isPhysical;
    }

    inline bool getIsWritable() const {
        return isWritable;
    }

    inline bool getHasBeenWritten() const {
        return hasBeenWritten;
    }

    inline void setValue(double value) {
        this->value = value;
    }

    inline void setPhysical(bool isPhysical) {
        this->isPhysical = isPhysical;
    }

    inline void setWritable(bool isWritable) {
        this->isWritable = isWritable;
    }

    inline void setHasBeenWritten(bool hasBeenWritten) {
        this->hasBeenWritten = hasBeenWritten;
    }

protected:
    double value;
    bool isPhysical;
    bool isWritable;
    bool hasBeenWritten;
};

#endif // VARIABLESTATE_H
