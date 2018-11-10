/*
 * Class definition to read basic Gyro information
 */
class Gyroscope {
  float pid_p_gain_roll = 0.60;               //Gain setting for the roll P-controller
  float pid_i_gain_roll = 0.04;              //Gain setting for the roll I-controller
  float pid_d_gain_roll = 7.0;               //Gain setting for the roll D-controller
  int pid_max_roll = 400;                    //Maximum output of the PID-controller (+/-)

  float pid_p_gain_pitch = pid_p_gain_roll;  //Gain setting for the pitch P-controller.
  float pid_i_gain_pitch = pid_i_gain_roll;  //Gain setting for the pitch I-controller.
  float pid_d_gain_pitch = pid_d_gain_roll;  //Gain setting for the pitch D-controller.
  int pid_max_pitch = pid_max_roll;          //Maximum output of the PID-controller (+/-)

  float pid_p_gain_yaw = 4.0;                //Gain setting for the pitch P-controller. //4.0
  float pid_i_gain_yaw = 0.02;               //Gain setting for the pitch I-controller. //0.02
  float pid_d_gain_yaw = 0.0;                //Gain setting for the pitch D-controller.
  int pid_max_yaw = 400;                     //Maximum output of the PID-controller (+/-)
  // PID Runtime variables.
  float pid_error_temp;
  float pid_i_mem_roll, pid_roll_setpoint, gyro_roll_input, pid_output_roll, pid_last_roll_d_error;
  float pid_i_mem_pitch, pid_pitch_setpoint, gyro_pitch_input, pid_output_pitch, pid_last_pitch_d_error;
  float pid_i_mem_yaw, pid_yaw_setpoint, gyro_yaw_input, pid_output_yaw, pid_last_yaw_d_error;

  // Variables for Gyro readings
  int gyro_address;
  int gyro_x, gyro_y, gyro_z;
  long acc_x, acc_y, acc_z, acc_total_vector;
  int temperature;
  long gyro_x_cal, gyro_y_cal, gyro_z_cal;
  float angle_pitch, angle_roll, angle_yaw;
  boolean set_gyro_angles;
  float angle_roll_acc, angle_pitch_acc, angle_yaw_acc;
  float angle_pitch_output, angle_roll_output, angle_yaw_output;

  // Internals methods for calibration.
  void setup_mpu_6050_registers();
  void read_mpu_6050_data();

public: 
  Gyroscope(int address);
  /**
   * This must to be called before any readings can be of use. This will read 2000 values from Gyroscope to compensate for drift 
   */
  void calibrate();
  /**
  * Call this function at a rate of once every 4 milli seconds. More frequent or less frequest than that will 
  * provide incorrect values for Angular Movement.
  */
  void read_angular_movement();
  void calculate_esc_adjustments();

  float get_pitch_angle();
  float get_roll_angle();
  float get_yaw_angle();
  float get_pitch_esc_adjustment();
  float get_roll_esc_adjustment();
  float get_yaw_esc_adjustment();  
};
