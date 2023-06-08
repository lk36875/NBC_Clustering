TEST_FOLDER="./evaluation_data"

RESULT_GOWER_FOLDER="./output_folder/results_gower"
RESULT_M_VDM_FOLDER="./output_folder/results_m_vdm"
RESULT_M_VDM_0_5_FOLDER="./output_folder/results_m_vdm_0_5"

LECTURE_NUM_csv="$TEST_FOLDER/lecture_examples/lecture_data_num.csv"
LECTURE_CARS_csv="$TEST_FOLDER/lecture_examples/lecture_data_cars.csv"


printf "\nLECTURE\n"
for i in 1 2 3; do
  ./build/MED-project "$LECTURE_NUM_csv" $i gower "$RESULT_GOWER_FOLDER/lecture_examples/num" double,double
  ./build/MED-project "$LECTURE_NUM_csv" $i manhattan "$RESULT_M_VDM_FOLDER/lecture_examples/num" double,double
  ./build/MED-project "$LECTURE_NUM_csv" $i gower "$RESULT_M_VDM_0_5_FOLDER/lecture_examples/num" double,double
  
  ./build/MED-project "$LECTURE_NUM_csv" $i gower "$RESULT_GOWER_FOLDER/lecture_examples/cars" double,double
  ./build/MED-project "$LECTURE_NUM_csv" $i manhattan "$RESULT_M_VDM_FOLDER/lecture_examples/cars" double,double
  ./build/MED-project "$LECTURE_NUM_csv" $i gower "$RESULT_M_VDM_0_5_FOLDER/lecture_examples/cars" double,double
done
