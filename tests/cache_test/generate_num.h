//
// Created by huawei on 20.05.2024.
//

#ifndef ARC_CASH_GENERAL_GENERATE_NUM_H
#define ARC_CASH_GENERAL_GENERATE_NUM_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <time.h>

/**
 * @brief Generates a sequence of page references and writes them to a file.
 *
 * This function generates a sequence of page references based on the given parameters:
 * - cache_size: the size of the cache.
 * - n_size: the number of page references to generate.
 * - max_page: the maximum page number.
 * - file: the file to which the generated page references will be written. **/
 
void generate(int cache_size, int n_size, int max_page, FILE *file);

#endif // ARC_CASH_GENERAL_GENERATE_NUM_H