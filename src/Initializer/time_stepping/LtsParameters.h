#ifndef SEISSOL_LTSCONFIGURATION_H
#define SEISSOL_LTSCONFIGURATION_H

#include <memory>
#include <yaml-cpp/yaml.h>

namespace seissol::time_stepping {
class LtsParameters {
  private:
  unsigned int rate;
  double wiggleFactorMinimum;
  double wiggleFactorStepsize;
  bool wiggleFactorEnforceMaximumDifference;

  public:
  [[nodiscard]] unsigned int getRate() const;
  [[nodiscard]] bool isWiggleFactorUsed() const;
  [[nodiscard]] double getWiggleFactorMinimum() const;
  [[nodiscard]] double getWiggleFactorStepsize() const;
  [[nodiscard]] bool getWiggleFactorEnforceMaximumDifference() const;

  LtsParameters(unsigned int rate,
                double wiggleFactorMinimum,
                double wiggleFactorStepsize,
                bool wiggleFactorEnforceMaximumDifference);
};

LtsParameters readLtsParametersFromYaml(std::shared_ptr<YAML::Node>& params);

} // namespace seissol::time_stepping

#endif // SEISSOL_LTSCONFIGURATION_H
