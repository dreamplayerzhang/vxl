#ifndef brad_processes_h_
#define brad_processes_h_

#include <bprb/bprb_func_process.h>
#include <bprb/bprb_macros.h>

//the init functions
DECLARE_FUNC_CONS(brad_display_sun_index_process);
DECLARE_FUNC_CONS(brad_sun_dir_bin_process);
DECLARE_FUNC_CONS(brad_save_sun_index_process);

DECLARE_FUNC_CONS(brad_create_eigenspace_process);
DECLARE_FUNC_CONS(brad_load_eigenspace_process);
DECLARE_FUNC_CONS(brad_save_eigenspace_process);
DECLARE_FUNC_CONS(brad_describe_eigenspace_process);
DECLARE_FUNC_CONS(brad_compute_eigenspace_process);

DECLARE_FUNC_CONS(brad_train_histograms_process);

DECLARE_FUNC_CONS(brad_update_joint_hist_3d_process);
DECLARE_FUNC_CONS(brad_classify_image_process);
DECLARE_FUNC_CONS(brad_classify_image_pixel_process);


DECLARE_FUNC_CONS(brad_estimate_phongs_model_process);
DECLARE_FUNC_CONS(brad_estimate_synoptic_function_1d_process);
DECLARE_FUNC_CONS(brad_estimate_empty_process);

DECLARE_FUNC_CONS(brad_estimate_shadow_model_process);
DECLARE_FUNC_CONS(brad_classify_image_pixel_process);
DECLARE_FUNC_CONS(brad_eigenimage_pixel_process);
DECLARE_FUNC_CONS(brad_nitf_abs_radiometric_calibration_process);
DECLARE_FUNC_CONS(brad_nitf_read_metadata_process);
DECLARE_FUNC_CONS(brad_estimate_atmospheric_parameters_process);
DECLARE_FUNC_CONS(brad_estimate_reflectance_process);

DECLARE_FUNC_CONS(brad_save_image_metadata_process);
DECLARE_FUNC_CONS(brad_save_atmospheric_parameters_process);
DECLARE_FUNC_CONS(brad_load_image_metadata_process);
DECLARE_FUNC_CONS(brad_load_atmospheric_parameters_process);

#endif
