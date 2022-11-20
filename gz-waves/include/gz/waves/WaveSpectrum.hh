// Copyright (C) 2019-2022  Rhys Mainwaring
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

#ifndef GZ_WAVES_WAVESPECTRUM_HH_
#define GZ_WAVES_WAVESPECTRUM_HH_

#include <Eigen/Dense>
 
using Eigen::MatrixXd;

namespace gz
{
namespace waves
{
inline namespace v2
{
  class OmniDirectionalWaveSpectrum
  {
  public:
    virtual ~OmniDirectionalWaveSpectrum();

    virtual double Evaluate(double k) const = 0;

    virtual void Evaluate(
        Eigen::Ref<Eigen::MatrixXd> spectrum,
        const Eigen::Ref<const Eigen::MatrixXd> &k) const = 0;
  };

  class PiersonMoskowitzWaveSpectrum : public OmniDirectionalWaveSpectrum
  {
  public:
    virtual ~PiersonMoskowitzWaveSpectrum();

    PiersonMoskowitzWaveSpectrum(double u19=5.0, double gravity=9.81);

    virtual double Evaluate(double k) const override;

    virtual void Evaluate(
        Eigen::Ref<Eigen::MatrixXd> spectrum,
        const Eigen::Ref<const Eigen::MatrixXd> &k) const override;

    double Gravity() const;

    void SetGravity(double value);

    double U19() const;

    void SetU19(double value);

  private:
    double gravity_{9.81};
    double u19_{5.0};
  };

  class ECKVWaveSpectrum : public OmniDirectionalWaveSpectrum
  {
  public:
    virtual ~ECKVWaveSpectrum();

    ECKVWaveSpectrum(
        double u10=5.0,
        double cap_omega_c=0.84,
        double gravity=9.81);

    virtual double Evaluate(double k) const override;

    virtual void Evaluate(
        Eigen::Ref<Eigen::MatrixXd> spectrum,
        const Eigen::Ref<const Eigen::MatrixXd> &k) const override;

    double Gravity() const;

    void SetGravity(double value);

    double U10() const;

    void SetU10(double value);

    double CapOmegaC() const;

    void SetCapOmegaC(double value);

  private:
    double gravity_{9.81};
    double u10_{5.0};
    double cap_omega_c_{0.84};
  };

}
}
}

#endif
