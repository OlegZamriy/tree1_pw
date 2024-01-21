#ifndef TRAFFICVIOLATION_H
#define TRAFFICVIOLATION_H

#include <string>

class TrafficViolation {
public:
    TrafficViolation(const std::string& violationType);
    std::string getViolationType() const;

private:
    std::string violationType;
};

#endif // TRAFFICVIOLATION_H
