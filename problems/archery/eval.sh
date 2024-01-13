for i in {0..19}
  do
    ./a.out  < upable/cases/case_${i}.in && cat upable/cases/case_${i}.out && echo ----
  done