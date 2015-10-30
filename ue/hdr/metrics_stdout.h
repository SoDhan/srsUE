/**
 *
 * \section COPYRIGHT
 *
 * Copyright 2015 The srsUE Developers. See the
 * COPYRIGHT file at the top-level directory of this distribution.
 *
 * \section LICENSE
 *
 * This file is part of the srsUE library.
 *
 * srsUE is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as
 * published by the Free Software Foundation, either version 3 of
 * the License, or (at your option) any later version.
 *
 * srsUE is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * A copy of the GNU Affero General Public License can be found in
 * the LICENSE file in the top-level directory of this distribution
 * and at http://www.gnu.org/licenses/.
 *
 */

/******************************************************************************
 * File:        metrics_stdout.h
 * Description: Metrics class printing to stdout.
 *****************************************************************************/

#ifndef METRICS_STDOUT_H
#define METRICS_STDOUT_H

#include <pthread.h>

#include "ue.h"

namespace srsue {

class metrics_stdout
{
public:
  metrics_stdout();

  bool init(ue *u);
  void stop();
  static void* metrics_thread_start(void *m);
  void metrics_thread_run();

private:
  void print_metrics();

  ue           *ue_;
  bool          first_connect;
  bool          started;
  pthread_t     metrics_thread;
  ue_metrics_t  metrics;
  uint32_t      metrics_report_period; // seconds
  uint8_t       n_reports;
};

} // namespace srsue

#endif // METRICS_STDOUT_H
