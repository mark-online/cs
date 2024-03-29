// Copyright (c) 2005-2014 Code Synthesis Tools CC
//
// This program was generated by CodeSynthesis XSD, an XML Schema to
// C++ data binding compiler.
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License version 2 as
// published by the Free Software Foundation.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
//
// In addition, as a special exception, Code Synthesis Tools CC gives
// permission to link this program with the Xerces-C++ library (or with
// modified versions of Xerces-C++ that use the same license as Xerces-C++),
// and distribute linked combinations including the two. You must obey
// the GNU General Public License version 2 in all respects for all of
// the code used other than Xerces-C++. If you modify this copy of the
// program, you may extend this exception to your version of the program,
// but you are not obligated to do so. If you do not wish to do so, delete
// this exception statement from your version.
//
// Furthermore, Code Synthesis Tools CC makes a special exception for
// the Free/Libre and Open Source Software (FLOSS) which is described
// in the accompanying FLOSSE file.
//

#ifndef GDT_ANCHOR_TABLE_IXX
#define GDT_ANCHOR_TABLE_IXX

// Begin prologue.
//
//
// End prologue.

#include "shared_types.ixx"

namespace gdt
{
  // anchor_t
  // 

  inline
  const anchor_t::anchor_code_type& anchor_t::
  anchor_code () const
  {
    return this->anchor_code_.get ();
  }

  inline
  anchor_t::anchor_code_type& anchor_t::
  anchor_code ()
  {
    return this->anchor_code_.get ();
  }

  inline
  void anchor_t::
  anchor_code (const anchor_code_type& x)
  {
    this->anchor_code_.set (x);
  }

  inline
  void anchor_t::
  anchor_code (::std::unique_ptr< anchor_code_type > x)
  {
    this->anchor_code_.set (std::move (x));
  }

  inline
  const anchor_t::achor_function_type_type& anchor_t::
  achor_function_type () const
  {
    return this->achor_function_type_.get ();
  }

  inline
  anchor_t::achor_function_type_type& anchor_t::
  achor_function_type ()
  {
    return this->achor_function_type_.get ();
  }

  inline
  void anchor_t::
  achor_function_type (const achor_function_type_type& x)
  {
    this->achor_function_type_.set (x);
  }

  inline
  const anchor_t::cooldown_mil_sec_type& anchor_t::
  cooldown_mil_sec () const
  {
    return this->cooldown_mil_sec_.get ();
  }

  inline
  anchor_t::cooldown_mil_sec_type& anchor_t::
  cooldown_mil_sec ()
  {
    return this->cooldown_mil_sec_.get ();
  }

  inline
  void anchor_t::
  cooldown_mil_sec (const cooldown_mil_sec_type& x)
  {
    this->cooldown_mil_sec_.set (x);
  }

  inline
  const anchor_t::live_sec_type& anchor_t::
  live_sec () const
  {
    return this->live_sec_.get ();
  }

  inline
  anchor_t::live_sec_type& anchor_t::
  live_sec ()
  {
    return this->live_sec_.get ();
  }

  inline
  void anchor_t::
  live_sec (const live_sec_type& x)
  {
    this->live_sec_.set (x);
  }

  inline
  const anchor_t::global_cooldown_index_type& anchor_t::
  global_cooldown_index () const
  {
    return this->global_cooldown_index_.get ();
  }

  inline
  anchor_t::global_cooldown_index_type& anchor_t::
  global_cooldown_index ()
  {
    return this->global_cooldown_index_.get ();
  }

  inline
  void anchor_t::
  global_cooldown_index (const global_cooldown_index_type& x)
  {
    this->global_cooldown_index_.set (x);
  }

  inline
  const anchor_t::global_cooldown_mil_sec_type& anchor_t::
  global_cooldown_mil_sec () const
  {
    return this->global_cooldown_mil_sec_.get ();
  }

  inline
  anchor_t::global_cooldown_mil_sec_type& anchor_t::
  global_cooldown_mil_sec ()
  {
    return this->global_cooldown_mil_sec_.get ();
  }

  inline
  void anchor_t::
  global_cooldown_mil_sec (const global_cooldown_mil_sec_type& x)
  {
    this->global_cooldown_mil_sec_.set (x);
  }

  inline
  const anchor_t::hp_type& anchor_t::
  hp () const
  {
    return this->hp_.get ();
  }

  inline
  anchor_t::hp_type& anchor_t::
  hp ()
  {
    return this->hp_.get ();
  }

  inline
  void anchor_t::
  hp (const hp_type& x)
  {
    this->hp_.set (x);
  }

  inline
  const anchor_t::defence_type& anchor_t::
  defence () const
  {
    return this->defence_.get ();
  }

  inline
  anchor_t::defence_type& anchor_t::
  defence ()
  {
    return this->defence_.get ();
  }

  inline
  void anchor_t::
  defence (const defence_type& x)
  {
    this->defence_.set (x);
  }

  inline
  const anchor_t::min_attack_power_type& anchor_t::
  min_attack_power () const
  {
    return this->min_attack_power_.get ();
  }

  inline
  anchor_t::min_attack_power_type& anchor_t::
  min_attack_power ()
  {
    return this->min_attack_power_.get ();
  }

  inline
  void anchor_t::
  min_attack_power (const min_attack_power_type& x)
  {
    this->min_attack_power_.set (x);
  }

  inline
  const anchor_t::max_attack_power_type& anchor_t::
  max_attack_power () const
  {
    return this->max_attack_power_.get ();
  }

  inline
  anchor_t::max_attack_power_type& anchor_t::
  max_attack_power ()
  {
    return this->max_attack_power_.get ();
  }

  inline
  void anchor_t::
  max_attack_power (const max_attack_power_type& x)
  {
    this->max_attack_power_.set (x);
  }

  inline
  const anchor_t::physical_attack_power_type& anchor_t::
  physical_attack_power () const
  {
    return this->physical_attack_power_.get ();
  }

  inline
  anchor_t::physical_attack_power_type& anchor_t::
  physical_attack_power ()
  {
    return this->physical_attack_power_.get ();
  }

  inline
  void anchor_t::
  physical_attack_power (const physical_attack_power_type& x)
  {
    this->physical_attack_power_.set (x);
  }

  inline
  const anchor_t::magic_attack_power_type& anchor_t::
  magic_attack_power () const
  {
    return this->magic_attack_power_.get ();
  }

  inline
  anchor_t::magic_attack_power_type& anchor_t::
  magic_attack_power ()
  {
    return this->magic_attack_power_.get ();
  }

  inline
  void anchor_t::
  magic_attack_power (const magic_attack_power_type& x)
  {
    this->magic_attack_power_.set (x);
  }

  inline
  const anchor_t::light_attribute_type& anchor_t::
  light_attribute () const
  {
    return this->light_attribute_.get ();
  }

  inline
  anchor_t::light_attribute_type& anchor_t::
  light_attribute ()
  {
    return this->light_attribute_.get ();
  }

  inline
  void anchor_t::
  light_attribute (const light_attribute_type& x)
  {
    this->light_attribute_.set (x);
  }

  inline
  const anchor_t::dark_attribute_type& anchor_t::
  dark_attribute () const
  {
    return this->dark_attribute_.get ();
  }

  inline
  anchor_t::dark_attribute_type& anchor_t::
  dark_attribute ()
  {
    return this->dark_attribute_.get ();
  }

  inline
  void anchor_t::
  dark_attribute (const dark_attribute_type& x)
  {
    this->dark_attribute_.set (x);
  }

  inline
  const anchor_t::fire_attribute_type& anchor_t::
  fire_attribute () const
  {
    return this->fire_attribute_.get ();
  }

  inline
  anchor_t::fire_attribute_type& anchor_t::
  fire_attribute ()
  {
    return this->fire_attribute_.get ();
  }

  inline
  void anchor_t::
  fire_attribute (const fire_attribute_type& x)
  {
    this->fire_attribute_.set (x);
  }

  inline
  const anchor_t::ice_attribute_type& anchor_t::
  ice_attribute () const
  {
    return this->ice_attribute_.get ();
  }

  inline
  anchor_t::ice_attribute_type& anchor_t::
  ice_attribute ()
  {
    return this->ice_attribute_.get ();
  }

  inline
  void anchor_t::
  ice_attribute (const ice_attribute_type& x)
  {
    this->ice_attribute_.set (x);
  }

  inline
  const anchor_t::light_attribute_regist_type& anchor_t::
  light_attribute_regist () const
  {
    return this->light_attribute_regist_.get ();
  }

  inline
  anchor_t::light_attribute_regist_type& anchor_t::
  light_attribute_regist ()
  {
    return this->light_attribute_regist_.get ();
  }

  inline
  void anchor_t::
  light_attribute_regist (const light_attribute_regist_type& x)
  {
    this->light_attribute_regist_.set (x);
  }

  inline
  const anchor_t::dark_attribute_regist_type& anchor_t::
  dark_attribute_regist () const
  {
    return this->dark_attribute_regist_.get ();
  }

  inline
  anchor_t::dark_attribute_regist_type& anchor_t::
  dark_attribute_regist ()
  {
    return this->dark_attribute_regist_.get ();
  }

  inline
  void anchor_t::
  dark_attribute_regist (const dark_attribute_regist_type& x)
  {
    this->dark_attribute_regist_.set (x);
  }

  inline
  const anchor_t::fire_attribute_regist_type& anchor_t::
  fire_attribute_regist () const
  {
    return this->fire_attribute_regist_.get ();
  }

  inline
  anchor_t::fire_attribute_regist_type& anchor_t::
  fire_attribute_regist ()
  {
    return this->fire_attribute_regist_.get ();
  }

  inline
  void anchor_t::
  fire_attribute_regist (const fire_attribute_regist_type& x)
  {
    this->fire_attribute_regist_.set (x);
  }

  inline
  const anchor_t::ice_attribute_regist_type& anchor_t::
  ice_attribute_regist () const
  {
    return this->ice_attribute_regist_.get ();
  }

  inline
  anchor_t::ice_attribute_regist_type& anchor_t::
  ice_attribute_regist ()
  {
    return this->ice_attribute_regist_.get ();
  }

  inline
  void anchor_t::
  ice_attribute_regist (const ice_attribute_regist_type& x)
  {
    this->ice_attribute_regist_.set (x);
  }

  inline
  const anchor_t::skill_code_type& anchor_t::
  skill_code () const
  {
    return this->skill_code_.get ();
  }

  inline
  anchor_t::skill_code_type& anchor_t::
  skill_code ()
  {
    return this->skill_code_.get ();
  }

  inline
  void anchor_t::
  skill_code (const skill_code_type& x)
  {
    this->skill_code_.set (x);
  }

  inline
  const anchor_t::active_interval_mil_sec_type& anchor_t::
  active_interval_mil_sec () const
  {
    return this->active_interval_mil_sec_.get ();
  }

  inline
  anchor_t::active_interval_mil_sec_type& anchor_t::
  active_interval_mil_sec ()
  {
    return this->active_interval_mil_sec_.get ();
  }

  inline
  void anchor_t::
  active_interval_mil_sec (const active_interval_mil_sec_type& x)
  {
    this->active_interval_mil_sec_.set (x);
  }

  inline
  const anchor_t::stack_count_type& anchor_t::
  stack_count () const
  {
    return this->stack_count_.get ();
  }

  inline
  anchor_t::stack_count_type& anchor_t::
  stack_count ()
  {
    return this->stack_count_.get ();
  }

  inline
  void anchor_t::
  stack_count (const stack_count_type& x)
  {
    this->stack_count_.set (x);
  }

  inline
  const anchor_t::sell_cost_type_type& anchor_t::
  sell_cost_type () const
  {
    return this->sell_cost_type_.get ();
  }

  inline
  anchor_t::sell_cost_type_type& anchor_t::
  sell_cost_type ()
  {
    return this->sell_cost_type_.get ();
  }

  inline
  void anchor_t::
  sell_cost_type (const sell_cost_type_type& x)
  {
    this->sell_cost_type_.set (x);
  }

  inline
  void anchor_t::
  sell_cost_type (::std::unique_ptr< sell_cost_type_type > x)
  {
    this->sell_cost_type_.set (std::move (x));
  }

  inline
  const anchor_t::sell_cost_type1& anchor_t::
  sell_cost () const
  {
    return this->sell_cost_.get ();
  }

  inline
  anchor_t::sell_cost_type1& anchor_t::
  sell_cost ()
  {
    return this->sell_cost_.get ();
  }

  inline
  void anchor_t::
  sell_cost (const sell_cost_type1& x)
  {
    this->sell_cost_.set (x);
  }

  inline
  const anchor_t::buy_cost_type_1_type& anchor_t::
  buy_cost_type_1 () const
  {
    return this->buy_cost_type_1_.get ();
  }

  inline
  anchor_t::buy_cost_type_1_type& anchor_t::
  buy_cost_type_1 ()
  {
    return this->buy_cost_type_1_.get ();
  }

  inline
  void anchor_t::
  buy_cost_type_1 (const buy_cost_type_1_type& x)
  {
    this->buy_cost_type_1_.set (x);
  }

  inline
  void anchor_t::
  buy_cost_type_1 (::std::unique_ptr< buy_cost_type_1_type > x)
  {
    this->buy_cost_type_1_.set (std::move (x));
  }

  inline
  const anchor_t::buy_cost_1_type& anchor_t::
  buy_cost_1 () const
  {
    return this->buy_cost_1_.get ();
  }

  inline
  anchor_t::buy_cost_1_type& anchor_t::
  buy_cost_1 ()
  {
    return this->buy_cost_1_.get ();
  }

  inline
  void anchor_t::
  buy_cost_1 (const buy_cost_1_type& x)
  {
    this->buy_cost_1_.set (x);
  }

  inline
  const anchor_t::buy_cost_type_2_type& anchor_t::
  buy_cost_type_2 () const
  {
    return this->buy_cost_type_2_.get ();
  }

  inline
  anchor_t::buy_cost_type_2_type& anchor_t::
  buy_cost_type_2 ()
  {
    return this->buy_cost_type_2_.get ();
  }

  inline
  void anchor_t::
  buy_cost_type_2 (const buy_cost_type_2_type& x)
  {
    this->buy_cost_type_2_.set (x);
  }

  inline
  void anchor_t::
  buy_cost_type_2 (::std::unique_ptr< buy_cost_type_2_type > x)
  {
    this->buy_cost_type_2_.set (std::move (x));
  }

  inline
  const anchor_t::buy_cost_2_type& anchor_t::
  buy_cost_2 () const
  {
    return this->buy_cost_2_.get ();
  }

  inline
  anchor_t::buy_cost_2_type& anchor_t::
  buy_cost_2 ()
  {
    return this->buy_cost_2_.get ();
  }

  inline
  void anchor_t::
  buy_cost_2 (const buy_cost_2_type& x)
  {
    this->buy_cost_2_.set (x);
  }

  inline
  const anchor_t::modeling_radius_type& anchor_t::
  modeling_radius () const
  {
    return this->modeling_radius_.get ();
  }

  inline
  anchor_t::modeling_radius_type& anchor_t::
  modeling_radius ()
  {
    return this->modeling_radius_.get ();
  }

  inline
  void anchor_t::
  modeling_radius (const modeling_radius_type& x)
  {
    this->modeling_radius_.set (x);
  }

  inline
  const anchor_t::icon_name_type& anchor_t::
  icon_name () const
  {
    return this->icon_name_.get ();
  }

  inline
  anchor_t::icon_name_type& anchor_t::
  icon_name ()
  {
    return this->icon_name_.get ();
  }

  inline
  void anchor_t::
  icon_name (const icon_name_type& x)
  {
    this->icon_name_.set (x);
  }

  inline
  void anchor_t::
  icon_name (::std::unique_ptr< icon_name_type > x)
  {
    this->icon_name_.set (std::move (x));
  }

  inline
  const anchor_t::build_modeling_type& anchor_t::
  build_modeling () const
  {
    return this->build_modeling_.get ();
  }

  inline
  anchor_t::build_modeling_type& anchor_t::
  build_modeling ()
  {
    return this->build_modeling_.get ();
  }

  inline
  void anchor_t::
  build_modeling (const build_modeling_type& x)
  {
    this->build_modeling_.set (x);
  }

  inline
  void anchor_t::
  build_modeling (::std::unique_ptr< build_modeling_type > x)
  {
    this->build_modeling_.set (std::move (x));
  }

  inline
  const anchor_t::build_animation_type& anchor_t::
  build_animation () const
  {
    return this->build_animation_.get ();
  }

  inline
  anchor_t::build_animation_type& anchor_t::
  build_animation ()
  {
    return this->build_animation_.get ();
  }

  inline
  void anchor_t::
  build_animation (const build_animation_type& x)
  {
    this->build_animation_.set (x);
  }

  inline
  void anchor_t::
  build_animation (::std::unique_ptr< build_animation_type > x)
  {
    this->build_animation_.set (std::move (x));
  }

  inline
  const anchor_t::build_sec_type& anchor_t::
  build_sec () const
  {
    return this->build_sec_.get ();
  }

  inline
  anchor_t::build_sec_type& anchor_t::
  build_sec ()
  {
    return this->build_sec_.get ();
  }

  inline
  void anchor_t::
  build_sec (const build_sec_type& x)
  {
    this->build_sec_.set (x);
  }

  inline
  const anchor_t::build_effect_type& anchor_t::
  build_effect () const
  {
    return this->build_effect_.get ();
  }

  inline
  anchor_t::build_effect_type& anchor_t::
  build_effect ()
  {
    return this->build_effect_.get ();
  }

  inline
  void anchor_t::
  build_effect (const build_effect_type& x)
  {
    this->build_effect_.set (x);
  }

  inline
  void anchor_t::
  build_effect (::std::unique_ptr< build_effect_type > x)
  {
    this->build_effect_.set (std::move (x));
  }

  inline
  const anchor_t::broken_animation_type& anchor_t::
  broken_animation () const
  {
    return this->broken_animation_.get ();
  }

  inline
  anchor_t::broken_animation_type& anchor_t::
  broken_animation ()
  {
    return this->broken_animation_.get ();
  }

  inline
  void anchor_t::
  broken_animation (const broken_animation_type& x)
  {
    this->broken_animation_.set (x);
  }

  inline
  void anchor_t::
  broken_animation (::std::unique_ptr< broken_animation_type > x)
  {
    this->broken_animation_.set (std::move (x));
  }

  inline
  const anchor_t::broken_effect_type& anchor_t::
  broken_effect () const
  {
    return this->broken_effect_.get ();
  }

  inline
  anchor_t::broken_effect_type& anchor_t::
  broken_effect ()
  {
    return this->broken_effect_.get ();
  }

  inline
  void anchor_t::
  broken_effect (const broken_effect_type& x)
  {
    this->broken_effect_.set (x);
  }

  inline
  void anchor_t::
  broken_effect (::std::unique_ptr< broken_effect_type > x)
  {
    this->broken_effect_.set (std::move (x));
  }

  inline
  const anchor_t::complete_modeling_type& anchor_t::
  complete_modeling () const
  {
    return this->complete_modeling_.get ();
  }

  inline
  anchor_t::complete_modeling_type& anchor_t::
  complete_modeling ()
  {
    return this->complete_modeling_.get ();
  }

  inline
  void anchor_t::
  complete_modeling (const complete_modeling_type& x)
  {
    this->complete_modeling_.set (x);
  }

  inline
  void anchor_t::
  complete_modeling (::std::unique_ptr< complete_modeling_type > x)
  {
    this->complete_modeling_.set (std::move (x));
  }


  // anchor_table
  // 

  inline
  const anchor_table::anchor_template_sequence& anchor_table::
  anchor_template () const
  {
    return this->anchor_template_;
  }

  inline
  anchor_table::anchor_template_sequence& anchor_table::
  anchor_template ()
  {
    return this->anchor_template_;
  }

  inline
  void anchor_table::
  anchor_template (const anchor_template_sequence& s)
  {
    this->anchor_template_ = s;
  }
}

// Begin epilogue.
//
//
// End epilogue.

#endif // GDT_ANCHOR_TABLE_IXX
