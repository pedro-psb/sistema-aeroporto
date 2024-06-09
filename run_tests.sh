#!/bin/bash

if [[ -z $1 ]]; then
  ctest --test-dir build
fi

if [[ $1 == "rerun" ]]; then
  ctest --test-dir build --rerun-failed --output-on-failure
fi
