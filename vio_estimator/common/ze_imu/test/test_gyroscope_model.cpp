// Copyright (c) 2015-2016, ETH Zurich, Wyss Zurich, Zurich Eye
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//     * Redistributions of source code must retain the above copyright
//       notice, this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above copyright
//       notice, this list of conditions and the following disclaimer in the
//       documentation and/or other materials provided with the distribution.
//     * Neither the name of the ETH Zurich, Wyss Zurich, Zurich Eye nor the
//       names of its contributors may be used to endorse or promote products
//       derived from this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
// ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
// WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL ETH Zurich, Wyss Zurich, Zurich Eye BE LIABLE FOR ANY
// DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
// (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
// LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
// ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
// SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#include <ze/common/test_entrypoint.hpp>

#include <ze/imu/gyroscope_model.hpp>
#include <ze/imu/imu_intrinsic_model.hpp>
#include <ze/imu/imu_noise_model.hpp>

TEST(GyroscopeModelTest, testGyroscope)
{
  using namespace ze;
  std::shared_ptr<ImuIntrinsicModelCalibrated> intrinsics =
      std::make_shared<ImuIntrinsicModelCalibrated>();
  std::shared_ptr<ImuNoiseNone> noise = std::make_shared<ImuNoiseNone>();

  GyroscopeModel model(intrinsics, noise);

  EXPECT_EQ(intrinsics, model.intrinsicModel());
  EXPECT_EQ(noise, model.noiseModel());
}

ZE_UNITTEST_ENTRYPOINT
