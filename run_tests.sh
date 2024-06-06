#!/bin/bash

for test in build/*_test; do
  echo "[TESTING] Running '${test}'"
  $test;
done
