/**
 * Copyright (C) 2011-2014 Joao Paulo de Souza Medeiros
 *
 * Author(s): Joao Paulo de Souza Medeiros <ignotus21@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#ifndef KALMAN_H
#define KALMAN_H

#include <stdio.h>
#include <stdlib.h>
#include "clann.h"
#include "matrix.h"

#define KALMAN_A_PRI    0
#define KALMAN_A_POS    1


/**
 * Kalman filter basic structure
 */
struct kalman
{
    clann_size_type n_state;
    clann_size_type n_measure;
    clann_size_type n_control;

    struct matrix state[2];     // state, x
    struct matrix measure;      // measure, y
    struct matrix control;      // control (input), u

    struct matrix m_process;    // state transition matrix, A
    struct matrix m_control;    // control (input) matrix, B
    struct matrix m_measure;    // measurement matrix, C
    struct matrix m_gain;       // kalman gain matrix, K
    struct matrix m_predict[2]; // prediction error covariance matrix, P

    struct matrix process_noise_cov;    // process noise covariance, Q
    struct matrix measure_noise_cov;    // measurement noise covariance, R
};


/**
 * Initialize an given kalman structure description
 */
void
kalman_initialize(struct kalman *k,
                  clann_size_type n_state,
                  clann_size_type n_measure,
                  clann_size_type n_control);

/**
 * Finalize an given kalman structure description
 */
void
kalman_finalize(struct kalman *k);

/**
 * 
 */
void
kalman_default(struct kalman *k);

/**
 * 
 */
void
kalman_predict(struct kalman *k);

/**
 * 
 */
void
kalman_correct(struct kalman *k);

#endif
