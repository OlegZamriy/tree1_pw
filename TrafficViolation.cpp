#include "TrafficViolation.h"

TrafficViolation::TrafficViolation(const std::string& violationType)
    : violationType(violationType) {}

std::string TrafficViolation::getViolationType() const {
    return violationType;
}
