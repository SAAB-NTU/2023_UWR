// Copyright 2022 Laboratory for Underwater Systems and Technologies (LABUST)
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

using System.Collections.Generic;
using MathNet.Numerics.LinearAlgebra;
using UnityEngine;

namespace Marus.Actuators
{
    public class DifferentialThrusterController : MonoBehaviour
    {

        public List<DifferentialThruster> thrusters = new List<DifferentialThruster>();

        public void ApplyInput(float[] array)
        {
            if (array.Length != thrusters.Count * 2)
            {
                Debug.Log("Input control vector does not match number of thrusters." +
                    "It should be 2 times longer");
                return;
            }
            for (int i = 0; i < thrusters.Count; i++)
            {
                if (i < array.Length/2)
                {
                    thrusters[i].ApplyInput(array[2*i], array[2*i + 1]);
                }
                else
                {
                    break;
                }
            }
        }
    }
}

