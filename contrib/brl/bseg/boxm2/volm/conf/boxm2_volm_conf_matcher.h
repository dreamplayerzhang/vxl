//This is brl/bseg/boxm2/volm/conf/boxm2_volm_conf_matcher.h
#ifndef boxm2_volm_conf_matcher_h_
#define boxm2_volm_conf_matcher_h_
//:
// \file
// \brief  A class to match a configurational query to pre-created configurational indices.  The output will be
//         a measurement (from 0 to 1) to quantify the similarity of configuration in the query and the index
//         Note that the matcher should be able to perform on both 2-d indices and 3-d indices
//
// \author Yi Dong
// \date August 27, 2014
// \verbatim
//   Modifications
//    <none yet>
// \endverbatim
//

#include <vgl/vgl_polygon.h>
#include <volm/volm_loc_hyp.h>
#include <volm/volm_loc_hyp_sptr.h>
#include <volm/volm_geo_index.h>
#include <volm/volm_geo_index_sptr.h>
#include <volm/conf/volm_conf_object.h>
#include <volm/conf/volm_conf_query.h>
#include <volm/conf/volm_conf_2d_indexer.h>
#include <volm/conf/volm_conf_score.h>

class boxm2_volm_conf_matcher
{
public:
  // =============== constructor ======================

  //: default constructor
  boxm2_volm_conf_matcher() {}
  boxm2_volm_conf_matcher(volm_conf_query_sptr const& query,
                          unsigned const& tile_id,
                          vcl_vector<volm_geo_index_node_sptr> const& loc_leaves,
                          vcl_string const& index_folder,
                          vcl_string const& out_folder,
                          vgl_polygon<double> const& cand_poly,
                          float const& buffer_capacity = 2.0);
  //: constructor to create query online
  boxm2_volm_conf_matcher(volm_camera_space_sptr const& cam_space, depth_map_scene_sptr const& depth_scene,
                          unsigned const& tile_id,
                          vcl_vector<volm_geo_index_node_sptr> const& loc_leaves,
                          vcl_string const& index_folder,
                          vcl_string const& out_folder,
                          vgl_polygon<double> const& cand_poly,
                          float const& buffer_capacity = 2.0,
                          unsigned tol_in_pixel = 25);

  ~boxm2_volm_conf_matcher() {}

  // =================== access =======================
  volm_conf_query_sptr query()    const { return query_; }
  vcl_string index_folder()       const { return index_folder_; }
  float buffer_capacity()         const { return buffer_capacity_; }
  vgl_polygon<double> cand_poly() const { return cand_poly_; }
  vcl_vector<volm_geo_index_node_sptr>& loc_leaves() { return loc_leaves_; }

  // =================== method =======================

  //: configurational matcher on location leaf with leaf_id (if leaf_id is -1, matcher will operate on all leaves)
  int conf_match_cpp(vcl_string const& index_name, int const& leaf_id = -1);

private:
  //: configurational query
  volm_conf_query_sptr query_;

  //: tile id where matcher operates on
  unsigned tile_id_;

  //: configurational index folder
  vcl_string index_folder_;

  //: location database
  vcl_vector<volm_geo_index_node_sptr> loc_leaves_;

  //: matcher related parameters
  float buffer_capacity_;  // in GB

  //: candidate polygon
  vgl_polygon<double> cand_poly_;
  bool is_cand_; // signature of candidate region being valid

  //: output folder
  vcl_string out_folder_;

  //: matching query with a single location index
  bool matching(vcl_vector<volm_conf_object> const& values, volm_conf_score& score);

  //: matching given a reference object point in index
  void match_to_reference(volm_conf_object const& ref_i, volm_conf_object_sptr const& ref_q,
                           vcl_vector<volm_conf_object_sptr> const& obj_q,
                           vcl_map<unsigned char, vcl_vector<volm_conf_object> >& obj_i,
                           float& score);
      

};

#endif // boxm2_volm_conf_matcher_h_