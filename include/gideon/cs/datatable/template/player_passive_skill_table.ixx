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

#ifndef GDT_PLAYER_PASSIVE_SKILL_TABLE_IXX
#define GDT_PLAYER_PASSIVE_SKILL_TABLE_IXX

// Begin prologue.
//
//
// End prologue.

#include "shared_types.ixx"

namespace gdt
{
  // player_passive_skill_t
  // 

  inline
  const player_passive_skill_t::skill_code_type& player_passive_skill_t::
  skill_code () const
  {
    return this->skill_code_.get ();
  }

  inline
  player_passive_skill_t::skill_code_type& player_passive_skill_t::
  skill_code ()
  {
    return this->skill_code_.get ();
  }

  inline
  void player_passive_skill_t::
  skill_code (const skill_code_type& x)
  {
    this->skill_code_.set (x);
  }

  inline
  void player_passive_skill_t::
  skill_code (::std::unique_ptr< skill_code_type > x)
  {
    this->skill_code_.set (std::move (x));
  }

  inline
  const player_passive_skill_t::effect_level_type& player_passive_skill_t::
  effect_level () const
  {
    return this->effect_level_.get ();
  }

  inline
  player_passive_skill_t::effect_level_type& player_passive_skill_t::
  effect_level ()
  {
    return this->effect_level_.get ();
  }

  inline
  void player_passive_skill_t::
  effect_level (const effect_level_type& x)
  {
    this->effect_level_.set (x);
  }

  inline
  const player_passive_skill_t::top_threat_apply_value_type& player_passive_skill_t::
  top_threat_apply_value () const
  {
    return this->top_threat_apply_value_.get ();
  }

  inline
  player_passive_skill_t::top_threat_apply_value_type& player_passive_skill_t::
  top_threat_apply_value ()
  {
    return this->top_threat_apply_value_.get ();
  }

  inline
  void player_passive_skill_t::
  top_threat_apply_value (const top_threat_apply_value_type& x)
  {
    this->top_threat_apply_value_.set (x);
  }

  inline
  const player_passive_skill_t::need_skill_point_type& player_passive_skill_t::
  need_skill_point () const
  {
    return this->need_skill_point_.get ();
  }

  inline
  player_passive_skill_t::need_skill_point_type& player_passive_skill_t::
  need_skill_point ()
  {
    return this->need_skill_point_.get ();
  }

  inline
  void player_passive_skill_t::
  need_skill_point (const need_skill_point_type& x)
  {
    this->need_skill_point_.set (x);
  }

  inline
  const player_passive_skill_t::learn_character_class_type& player_passive_skill_t::
  learn_character_class () const
  {
    return this->learn_character_class_.get ();
  }

  inline
  player_passive_skill_t::learn_character_class_type& player_passive_skill_t::
  learn_character_class ()
  {
    return this->learn_character_class_.get ();
  }

  inline
  void player_passive_skill_t::
  learn_character_class (const learn_character_class_type& x)
  {
    this->learn_character_class_.set (x);
  }

  inline
  const player_passive_skill_t::need_learn_skill_code_1_type& player_passive_skill_t::
  need_learn_skill_code_1 () const
  {
    return this->need_learn_skill_code_1_.get ();
  }

  inline
  player_passive_skill_t::need_learn_skill_code_1_type& player_passive_skill_t::
  need_learn_skill_code_1 ()
  {
    return this->need_learn_skill_code_1_.get ();
  }

  inline
  void player_passive_skill_t::
  need_learn_skill_code_1 (const need_learn_skill_code_1_type& x)
  {
    this->need_learn_skill_code_1_.set (x);
  }

  inline
  void player_passive_skill_t::
  need_learn_skill_code_1 (::std::unique_ptr< need_learn_skill_code_1_type > x)
  {
    this->need_learn_skill_code_1_.set (std::move (x));
  }

  inline
  player_passive_skill_t::need_learn_skill_code_1_type player_passive_skill_t::
  need_learn_skill_code_1_default_value ()
  {
    return need_learn_skill_code_1_type (0U);
  }

  inline
  const player_passive_skill_t::need_learn_skill_code_2_type& player_passive_skill_t::
  need_learn_skill_code_2 () const
  {
    return this->need_learn_skill_code_2_.get ();
  }

  inline
  player_passive_skill_t::need_learn_skill_code_2_type& player_passive_skill_t::
  need_learn_skill_code_2 ()
  {
    return this->need_learn_skill_code_2_.get ();
  }

  inline
  void player_passive_skill_t::
  need_learn_skill_code_2 (const need_learn_skill_code_2_type& x)
  {
    this->need_learn_skill_code_2_.set (x);
  }

  inline
  void player_passive_skill_t::
  need_learn_skill_code_2 (::std::unique_ptr< need_learn_skill_code_2_type > x)
  {
    this->need_learn_skill_code_2_.set (std::move (x));
  }

  inline
  player_passive_skill_t::need_learn_skill_code_2_type player_passive_skill_t::
  need_learn_skill_code_2_default_value ()
  {
    return need_learn_skill_code_2_type (0U);
  }

  inline
  const player_passive_skill_t::next_skill_code_1_type& player_passive_skill_t::
  next_skill_code_1 () const
  {
    return this->next_skill_code_1_.get ();
  }

  inline
  player_passive_skill_t::next_skill_code_1_type& player_passive_skill_t::
  next_skill_code_1 ()
  {
    return this->next_skill_code_1_.get ();
  }

  inline
  void player_passive_skill_t::
  next_skill_code_1 (const next_skill_code_1_type& x)
  {
    this->next_skill_code_1_.set (x);
  }

  inline
  void player_passive_skill_t::
  next_skill_code_1 (::std::unique_ptr< next_skill_code_1_type > x)
  {
    this->next_skill_code_1_.set (std::move (x));
  }

  inline
  player_passive_skill_t::next_skill_code_1_type player_passive_skill_t::
  next_skill_code_1_default_value ()
  {
    return next_skill_code_1_type (0U);
  }

  inline
  const player_passive_skill_t::next_skill_code_2_type& player_passive_skill_t::
  next_skill_code_2 () const
  {
    return this->next_skill_code_2_.get ();
  }

  inline
  player_passive_skill_t::next_skill_code_2_type& player_passive_skill_t::
  next_skill_code_2 ()
  {
    return this->next_skill_code_2_.get ();
  }

  inline
  void player_passive_skill_t::
  next_skill_code_2 (const next_skill_code_2_type& x)
  {
    this->next_skill_code_2_.set (x);
  }

  inline
  void player_passive_skill_t::
  next_skill_code_2 (::std::unique_ptr< next_skill_code_2_type > x)
  {
    this->next_skill_code_2_.set (std::move (x));
  }

  inline
  player_passive_skill_t::next_skill_code_2_type player_passive_skill_t::
  next_skill_code_2_default_value ()
  {
    return next_skill_code_2_type (0U);
  }

  inline
  const player_passive_skill_t::check_equip_part_type& player_passive_skill_t::
  check_equip_part () const
  {
    return this->check_equip_part_.get ();
  }

  inline
  player_passive_skill_t::check_equip_part_type& player_passive_skill_t::
  check_equip_part ()
  {
    return this->check_equip_part_.get ();
  }

  inline
  void player_passive_skill_t::
  check_equip_part (const check_equip_part_type& x)
  {
    this->check_equip_part_.set (x);
  }

  inline
  void player_passive_skill_t::
  check_equip_part (::std::unique_ptr< check_equip_part_type > x)
  {
    this->check_equip_part_.set (std::move (x));
  }

  inline
  const player_passive_skill_t::check_castable_equip_type_type& player_passive_skill_t::
  check_castable_equip_type () const
  {
    return this->check_castable_equip_type_.get ();
  }

  inline
  player_passive_skill_t::check_castable_equip_type_type& player_passive_skill_t::
  check_castable_equip_type ()
  {
    return this->check_castable_equip_type_.get ();
  }

  inline
  void player_passive_skill_t::
  check_castable_equip_type (const check_castable_equip_type_type& x)
  {
    this->check_castable_equip_type_.set (x);
  }

  inline
  void player_passive_skill_t::
  check_castable_equip_type (::std::unique_ptr< check_castable_equip_type_type > x)
  {
    this->check_castable_equip_type_.set (std::move (x));
  }

  inline
  const player_passive_skill_t::skill_type_type& player_passive_skill_t::
  skill_type () const
  {
    return this->skill_type_.get ();
  }

  inline
  player_passive_skill_t::skill_type_type& player_passive_skill_t::
  skill_type ()
  {
    return this->skill_type_.get ();
  }

  inline
  void player_passive_skill_t::
  skill_type (const skill_type_type& x)
  {
    this->skill_type_.set (x);
  }

  inline
  void player_passive_skill_t::
  skill_type (::std::unique_ptr< skill_type_type > x)
  {
    this->skill_type_.set (std::move (x));
  }

  inline
  const player_passive_skill_t::usable_state_type& player_passive_skill_t::
  usable_state () const
  {
    return this->usable_state_.get ();
  }

  inline
  player_passive_skill_t::usable_state_type& player_passive_skill_t::
  usable_state ()
  {
    return this->usable_state_.get ();
  }

  inline
  void player_passive_skill_t::
  usable_state (const usable_state_type& x)
  {
    this->usable_state_.set (x);
  }

  inline
  void player_passive_skill_t::
  usable_state (::std::unique_ptr< usable_state_type > x)
  {
    this->usable_state_.set (std::move (x));
  }

  inline
  const player_passive_skill_t::check_point_target_type_type& player_passive_skill_t::
  check_point_target_type () const
  {
    return this->check_point_target_type_.get ();
  }

  inline
  player_passive_skill_t::check_point_target_type_type& player_passive_skill_t::
  check_point_target_type ()
  {
    return this->check_point_target_type_.get ();
  }

  inline
  void player_passive_skill_t::
  check_point_target_type (const check_point_target_type_type& x)
  {
    this->check_point_target_type_.set (x);
  }

  inline
  const player_passive_skill_t::check_point_type_type& player_passive_skill_t::
  check_point_type () const
  {
    return this->check_point_type_.get ();
  }

  inline
  player_passive_skill_t::check_point_type_type& player_passive_skill_t::
  check_point_type ()
  {
    return this->check_point_type_.get ();
  }

  inline
  void player_passive_skill_t::
  check_point_type (const check_point_type_type& x)
  {
    this->check_point_type_.set (x);
  }

  inline
  const player_passive_skill_t::check_point_up_down_type& player_passive_skill_t::
  check_point_up_down () const
  {
    return this->check_point_up_down_.get ();
  }

  inline
  player_passive_skill_t::check_point_up_down_type& player_passive_skill_t::
  check_point_up_down ()
  {
    return this->check_point_up_down_.get ();
  }

  inline
  void player_passive_skill_t::
  check_point_up_down (const check_point_up_down_type& x)
  {
    this->check_point_up_down_.set (x);
  }

  inline
  const player_passive_skill_t::check_point_value_by_percent_type& player_passive_skill_t::
  check_point_value_by_percent () const
  {
    return this->check_point_value_by_percent_.get ();
  }

  inline
  player_passive_skill_t::check_point_value_by_percent_type& player_passive_skill_t::
  check_point_value_by_percent ()
  {
    return this->check_point_value_by_percent_.get ();
  }

  inline
  void player_passive_skill_t::
  check_point_value_by_percent (const check_point_value_by_percent_type& x)
  {
    this->check_point_value_by_percent_.set (x);
  }

  inline
  const player_passive_skill_t::check_point_value_type& player_passive_skill_t::
  check_point_value () const
  {
    return this->check_point_value_.get ();
  }

  inline
  player_passive_skill_t::check_point_value_type& player_passive_skill_t::
  check_point_value ()
  {
    return this->check_point_value_.get ();
  }

  inline
  void player_passive_skill_t::
  check_point_value (const check_point_value_type& x)
  {
    this->check_point_value_.set (x);
  }

  inline
  const player_passive_skill_t::cooldown_time_type& player_passive_skill_t::
  cooldown_time () const
  {
    return this->cooldown_time_.get ();
  }

  inline
  player_passive_skill_t::cooldown_time_type& player_passive_skill_t::
  cooldown_time ()
  {
    return this->cooldown_time_.get ();
  }

  inline
  void player_passive_skill_t::
  cooldown_time (const cooldown_time_type& x)
  {
    this->cooldown_time_.set (x);
  }

  inline
  const player_passive_skill_t::global_cooldown_time_index_type& player_passive_skill_t::
  global_cooldown_time_index () const
  {
    return this->global_cooldown_time_index_.get ();
  }

  inline
  player_passive_skill_t::global_cooldown_time_index_type& player_passive_skill_t::
  global_cooldown_time_index ()
  {
    return this->global_cooldown_time_index_.get ();
  }

  inline
  void player_passive_skill_t::
  global_cooldown_time_index (const global_cooldown_time_index_type& x)
  {
    this->global_cooldown_time_index_.set (x);
  }

  inline
  const player_passive_skill_t::global_cooldown_time_type& player_passive_skill_t::
  global_cooldown_time () const
  {
    return this->global_cooldown_time_.get ();
  }

  inline
  player_passive_skill_t::global_cooldown_time_type& player_passive_skill_t::
  global_cooldown_time ()
  {
    return this->global_cooldown_time_.get ();
  }

  inline
  void player_passive_skill_t::
  global_cooldown_time (const global_cooldown_time_type& x)
  {
    this->global_cooldown_time_.set (x);
  }

  inline
  const player_passive_skill_t::caster_activate_mil_sec_1_type& player_passive_skill_t::
  caster_activate_mil_sec_1 () const
  {
    return this->caster_activate_mil_sec_1_.get ();
  }

  inline
  player_passive_skill_t::caster_activate_mil_sec_1_type& player_passive_skill_t::
  caster_activate_mil_sec_1 ()
  {
    return this->caster_activate_mil_sec_1_.get ();
  }

  inline
  void player_passive_skill_t::
  caster_activate_mil_sec_1 (const caster_activate_mil_sec_1_type& x)
  {
    this->caster_activate_mil_sec_1_.set (x);
  }

  inline
  const player_passive_skill_t::caster_activate_interval_mil_sec_1_type& player_passive_skill_t::
  caster_activate_interval_mil_sec_1 () const
  {
    return this->caster_activate_interval_mil_sec_1_.get ();
  }

  inline
  player_passive_skill_t::caster_activate_interval_mil_sec_1_type& player_passive_skill_t::
  caster_activate_interval_mil_sec_1 ()
  {
    return this->caster_activate_interval_mil_sec_1_.get ();
  }

  inline
  void player_passive_skill_t::
  caster_activate_interval_mil_sec_1 (const caster_activate_interval_mil_sec_1_type& x)
  {
    this->caster_activate_interval_mil_sec_1_.set (x);
  }

  inline
  const player_passive_skill_t::caster_activate_mil_sec_2_type& player_passive_skill_t::
  caster_activate_mil_sec_2 () const
  {
    return this->caster_activate_mil_sec_2_.get ();
  }

  inline
  player_passive_skill_t::caster_activate_mil_sec_2_type& player_passive_skill_t::
  caster_activate_mil_sec_2 ()
  {
    return this->caster_activate_mil_sec_2_.get ();
  }

  inline
  void player_passive_skill_t::
  caster_activate_mil_sec_2 (const caster_activate_mil_sec_2_type& x)
  {
    this->caster_activate_mil_sec_2_.set (x);
  }

  inline
  const player_passive_skill_t::caster_activate_interval_mil_sec_2_type& player_passive_skill_t::
  caster_activate_interval_mil_sec_2 () const
  {
    return this->caster_activate_interval_mil_sec_2_.get ();
  }

  inline
  player_passive_skill_t::caster_activate_interval_mil_sec_2_type& player_passive_skill_t::
  caster_activate_interval_mil_sec_2 ()
  {
    return this->caster_activate_interval_mil_sec_2_.get ();
  }

  inline
  void player_passive_skill_t::
  caster_activate_interval_mil_sec_2 (const caster_activate_interval_mil_sec_2_type& x)
  {
    this->caster_activate_interval_mil_sec_2_.set (x);
  }

  inline
  const player_passive_skill_t::castee_activate_mil_sec_1_type& player_passive_skill_t::
  castee_activate_mil_sec_1 () const
  {
    return this->castee_activate_mil_sec_1_.get ();
  }

  inline
  player_passive_skill_t::castee_activate_mil_sec_1_type& player_passive_skill_t::
  castee_activate_mil_sec_1 ()
  {
    return this->castee_activate_mil_sec_1_.get ();
  }

  inline
  void player_passive_skill_t::
  castee_activate_mil_sec_1 (const castee_activate_mil_sec_1_type& x)
  {
    this->castee_activate_mil_sec_1_.set (x);
  }

  inline
  const player_passive_skill_t::castee_activate_interval_mil_sec_1_type& player_passive_skill_t::
  castee_activate_interval_mil_sec_1 () const
  {
    return this->castee_activate_interval_mil_sec_1_.get ();
  }

  inline
  player_passive_skill_t::castee_activate_interval_mil_sec_1_type& player_passive_skill_t::
  castee_activate_interval_mil_sec_1 ()
  {
    return this->castee_activate_interval_mil_sec_1_.get ();
  }

  inline
  void player_passive_skill_t::
  castee_activate_interval_mil_sec_1 (const castee_activate_interval_mil_sec_1_type& x)
  {
    this->castee_activate_interval_mil_sec_1_.set (x);
  }

  inline
  const player_passive_skill_t::castee_activate_mil_sec_2_type& player_passive_skill_t::
  castee_activate_mil_sec_2 () const
  {
    return this->castee_activate_mil_sec_2_.get ();
  }

  inline
  player_passive_skill_t::castee_activate_mil_sec_2_type& player_passive_skill_t::
  castee_activate_mil_sec_2 ()
  {
    return this->castee_activate_mil_sec_2_.get ();
  }

  inline
  void player_passive_skill_t::
  castee_activate_mil_sec_2 (const castee_activate_mil_sec_2_type& x)
  {
    this->castee_activate_mil_sec_2_.set (x);
  }

  inline
  const player_passive_skill_t::castee_activate_interval_mil_sec_2_type& player_passive_skill_t::
  castee_activate_interval_mil_sec_2 () const
  {
    return this->castee_activate_interval_mil_sec_2_.get ();
  }

  inline
  player_passive_skill_t::castee_activate_interval_mil_sec_2_type& player_passive_skill_t::
  castee_activate_interval_mil_sec_2 ()
  {
    return this->castee_activate_interval_mil_sec_2_.get ();
  }

  inline
  void player_passive_skill_t::
  castee_activate_interval_mil_sec_2 (const castee_activate_interval_mil_sec_2_type& x)
  {
    this->castee_activate_interval_mil_sec_2_.set (x);
  }

  inline
  const player_passive_skill_t::skill_effect_index_type& player_passive_skill_t::
  skill_effect_index () const
  {
    return this->skill_effect_index_.get ();
  }

  inline
  player_passive_skill_t::skill_effect_index_type& player_passive_skill_t::
  skill_effect_index ()
  {
    return this->skill_effect_index_.get ();
  }

  inline
  void player_passive_skill_t::
  skill_effect_index (const skill_effect_index_type& x)
  {
    this->skill_effect_index_.set (x);
  }

  inline
  const player_passive_skill_t::caster_effect_value_1_type& player_passive_skill_t::
  caster_effect_value_1 () const
  {
    return this->caster_effect_value_1_.get ();
  }

  inline
  player_passive_skill_t::caster_effect_value_1_type& player_passive_skill_t::
  caster_effect_value_1 ()
  {
    return this->caster_effect_value_1_.get ();
  }

  inline
  void player_passive_skill_t::
  caster_effect_value_1 (const caster_effect_value_1_type& x)
  {
    this->caster_effect_value_1_.set (x);
  }

  inline
  const player_passive_skill_t::caster_effect_value_2_type& player_passive_skill_t::
  caster_effect_value_2 () const
  {
    return this->caster_effect_value_2_.get ();
  }

  inline
  player_passive_skill_t::caster_effect_value_2_type& player_passive_skill_t::
  caster_effect_value_2 ()
  {
    return this->caster_effect_value_2_.get ();
  }

  inline
  void player_passive_skill_t::
  caster_effect_value_2 (const caster_effect_value_2_type& x)
  {
    this->caster_effect_value_2_.set (x);
  }

  inline
  const player_passive_skill_t::castee_effect_value_1_type& player_passive_skill_t::
  castee_effect_value_1 () const
  {
    return this->castee_effect_value_1_.get ();
  }

  inline
  player_passive_skill_t::castee_effect_value_1_type& player_passive_skill_t::
  castee_effect_value_1 ()
  {
    return this->castee_effect_value_1_.get ();
  }

  inline
  void player_passive_skill_t::
  castee_effect_value_1 (const castee_effect_value_1_type& x)
  {
    this->castee_effect_value_1_.set (x);
  }

  inline
  const player_passive_skill_t::castee_effect_value_2_type& player_passive_skill_t::
  castee_effect_value_2 () const
  {
    return this->castee_effect_value_2_.get ();
  }

  inline
  player_passive_skill_t::castee_effect_value_2_type& player_passive_skill_t::
  castee_effect_value_2 ()
  {
    return this->castee_effect_value_2_.get ();
  }

  inline
  void player_passive_skill_t::
  castee_effect_value_2 (const castee_effect_value_2_type& x)
  {
    this->castee_effect_value_2_.set (x);
  }

  inline
  const player_passive_skill_t::icon_name_type& player_passive_skill_t::
  icon_name () const
  {
    return this->icon_name_.get ();
  }

  inline
  player_passive_skill_t::icon_name_type& player_passive_skill_t::
  icon_name ()
  {
    return this->icon_name_.get ();
  }

  inline
  void player_passive_skill_t::
  icon_name (const icon_name_type& x)
  {
    this->icon_name_.set (x);
  }

  inline
  void player_passive_skill_t::
  icon_name (::std::unique_ptr< icon_name_type > x)
  {
    this->icon_name_.set (std::move (x));
  }

  inline
  const player_passive_skill_t::casting_animation_name_type& player_passive_skill_t::
  casting_animation_name () const
  {
    return this->casting_animation_name_.get ();
  }

  inline
  player_passive_skill_t::casting_animation_name_type& player_passive_skill_t::
  casting_animation_name ()
  {
    return this->casting_animation_name_.get ();
  }

  inline
  void player_passive_skill_t::
  casting_animation_name (const casting_animation_name_type& x)
  {
    this->casting_animation_name_.set (x);
  }

  inline
  void player_passive_skill_t::
  casting_animation_name (::std::unique_ptr< casting_animation_name_type > x)
  {
    this->casting_animation_name_.set (std::move (x));
  }

  inline
  const player_passive_skill_t::casting_draw_animation_name_type& player_passive_skill_t::
  casting_draw_animation_name () const
  {
    return this->casting_draw_animation_name_.get ();
  }

  inline
  player_passive_skill_t::casting_draw_animation_name_type& player_passive_skill_t::
  casting_draw_animation_name ()
  {
    return this->casting_draw_animation_name_.get ();
  }

  inline
  void player_passive_skill_t::
  casting_draw_animation_name (const casting_draw_animation_name_type& x)
  {
    this->casting_draw_animation_name_.set (x);
  }

  inline
  void player_passive_skill_t::
  casting_draw_animation_name (::std::unique_ptr< casting_draw_animation_name_type > x)
  {
    this->casting_draw_animation_name_.set (std::move (x));
  }

  inline
  const player_passive_skill_t::casting_effect_type& player_passive_skill_t::
  casting_effect () const
  {
    return this->casting_effect_.get ();
  }

  inline
  player_passive_skill_t::casting_effect_type& player_passive_skill_t::
  casting_effect ()
  {
    return this->casting_effect_.get ();
  }

  inline
  void player_passive_skill_t::
  casting_effect (const casting_effect_type& x)
  {
    this->casting_effect_.set (x);
  }

  inline
  void player_passive_skill_t::
  casting_effect (::std::unique_ptr< casting_effect_type > x)
  {
    this->casting_effect_.set (std::move (x));
  }

  inline
  const player_passive_skill_t::animation_transition_time_type& player_passive_skill_t::
  animation_transition_time () const
  {
    return this->animation_transition_time_.get ();
  }

  inline
  player_passive_skill_t::animation_transition_time_type& player_passive_skill_t::
  animation_transition_time ()
  {
    return this->animation_transition_time_.get ();
  }

  inline
  void player_passive_skill_t::
  animation_transition_time (const animation_transition_time_type& x)
  {
    this->animation_transition_time_.set (x);
  }

  inline
  const player_passive_skill_t::caster_animation_name_type& player_passive_skill_t::
  caster_animation_name () const
  {
    return this->caster_animation_name_.get ();
  }

  inline
  player_passive_skill_t::caster_animation_name_type& player_passive_skill_t::
  caster_animation_name ()
  {
    return this->caster_animation_name_.get ();
  }

  inline
  void player_passive_skill_t::
  caster_animation_name (const caster_animation_name_type& x)
  {
    this->caster_animation_name_.set (x);
  }

  inline
  void player_passive_skill_t::
  caster_animation_name (::std::unique_ptr< caster_animation_name_type > x)
  {
    this->caster_animation_name_.set (std::move (x));
  }

  inline
  const player_passive_skill_t::caster_effect_type& player_passive_skill_t::
  caster_effect () const
  {
    return this->caster_effect_.get ();
  }

  inline
  player_passive_skill_t::caster_effect_type& player_passive_skill_t::
  caster_effect ()
  {
    return this->caster_effect_.get ();
  }

  inline
  void player_passive_skill_t::
  caster_effect (const caster_effect_type& x)
  {
    this->caster_effect_.set (x);
  }

  inline
  void player_passive_skill_t::
  caster_effect (::std::unique_ptr< caster_effect_type > x)
  {
    this->caster_effect_.set (std::move (x));
  }

  inline
  const player_passive_skill_t::trail_effect_type& player_passive_skill_t::
  trail_effect () const
  {
    return this->trail_effect_.get ();
  }

  inline
  player_passive_skill_t::trail_effect_type& player_passive_skill_t::
  trail_effect ()
  {
    return this->trail_effect_.get ();
  }

  inline
  void player_passive_skill_t::
  trail_effect (const trail_effect_type& x)
  {
    this->trail_effect_.set (x);
  }

  inline
  void player_passive_skill_t::
  trail_effect (::std::unique_ptr< trail_effect_type > x)
  {
    this->trail_effect_.set (std::move (x));
  }

  inline
  const player_passive_skill_t::attacker1_caster_effect_type& player_passive_skill_t::
  attacker1_caster_effect () const
  {
    return this->attacker1_caster_effect_.get ();
  }

  inline
  player_passive_skill_t::attacker1_caster_effect_type& player_passive_skill_t::
  attacker1_caster_effect ()
  {
    return this->attacker1_caster_effect_.get ();
  }

  inline
  void player_passive_skill_t::
  attacker1_caster_effect (const attacker1_caster_effect_type& x)
  {
    this->attacker1_caster_effect_.set (x);
  }

  inline
  void player_passive_skill_t::
  attacker1_caster_effect (::std::unique_ptr< attacker1_caster_effect_type > x)
  {
    this->attacker1_caster_effect_.set (std::move (x));
  }

  inline
  const player_passive_skill_t::attacker2_caster_effect_type& player_passive_skill_t::
  attacker2_caster_effect () const
  {
    return this->attacker2_caster_effect_.get ();
  }

  inline
  player_passive_skill_t::attacker2_caster_effect_type& player_passive_skill_t::
  attacker2_caster_effect ()
  {
    return this->attacker2_caster_effect_.get ();
  }

  inline
  void player_passive_skill_t::
  attacker2_caster_effect (const attacker2_caster_effect_type& x)
  {
    this->attacker2_caster_effect_.set (x);
  }

  inline
  void player_passive_skill_t::
  attacker2_caster_effect (::std::unique_ptr< attacker2_caster_effect_type > x)
  {
    this->attacker2_caster_effect_.set (std::move (x));
  }

  inline
  const player_passive_skill_t::castee_animation_name_type& player_passive_skill_t::
  castee_animation_name () const
  {
    return this->castee_animation_name_.get ();
  }

  inline
  player_passive_skill_t::castee_animation_name_type& player_passive_skill_t::
  castee_animation_name ()
  {
    return this->castee_animation_name_.get ();
  }

  inline
  void player_passive_skill_t::
  castee_animation_name (const castee_animation_name_type& x)
  {
    this->castee_animation_name_.set (x);
  }

  inline
  void player_passive_skill_t::
  castee_animation_name (::std::unique_ptr< castee_animation_name_type > x)
  {
    this->castee_animation_name_.set (std::move (x));
  }

  inline
  const player_passive_skill_t::castee_interval_time_type& player_passive_skill_t::
  castee_interval_time () const
  {
    return this->castee_interval_time_.get ();
  }

  inline
  player_passive_skill_t::castee_interval_time_type& player_passive_skill_t::
  castee_interval_time ()
  {
    return this->castee_interval_time_.get ();
  }

  inline
  void player_passive_skill_t::
  castee_interval_time (const castee_interval_time_type& x)
  {
    this->castee_interval_time_.set (x);
  }

  inline
  const player_passive_skill_t::attacked1_castee_effect_type& player_passive_skill_t::
  attacked1_castee_effect () const
  {
    return this->attacked1_castee_effect_.get ();
  }

  inline
  player_passive_skill_t::attacked1_castee_effect_type& player_passive_skill_t::
  attacked1_castee_effect ()
  {
    return this->attacked1_castee_effect_.get ();
  }

  inline
  void player_passive_skill_t::
  attacked1_castee_effect (const attacked1_castee_effect_type& x)
  {
    this->attacked1_castee_effect_.set (x);
  }

  inline
  void player_passive_skill_t::
  attacked1_castee_effect (::std::unique_ptr< attacked1_castee_effect_type > x)
  {
    this->attacked1_castee_effect_.set (std::move (x));
  }

  inline
  const player_passive_skill_t::attacked2_castee_effect_type& player_passive_skill_t::
  attacked2_castee_effect () const
  {
    return this->attacked2_castee_effect_.get ();
  }

  inline
  player_passive_skill_t::attacked2_castee_effect_type& player_passive_skill_t::
  attacked2_castee_effect ()
  {
    return this->attacked2_castee_effect_.get ();
  }

  inline
  void player_passive_skill_t::
  attacked2_castee_effect (const attacked2_castee_effect_type& x)
  {
    this->attacked2_castee_effect_.set (x);
  }

  inline
  void player_passive_skill_t::
  attacked2_castee_effect (::std::unique_ptr< attacked2_castee_effect_type > x)
  {
    this->attacked2_castee_effect_.set (std::move (x));
  }

  inline
  const player_passive_skill_t::area_effect_type& player_passive_skill_t::
  area_effect () const
  {
    return this->area_effect_.get ();
  }

  inline
  player_passive_skill_t::area_effect_type& player_passive_skill_t::
  area_effect ()
  {
    return this->area_effect_.get ();
  }

  inline
  void player_passive_skill_t::
  area_effect (const area_effect_type& x)
  {
    this->area_effect_.set (x);
  }

  inline
  void player_passive_skill_t::
  area_effect (::std::unique_ptr< area_effect_type > x)
  {
    this->area_effect_.set (std::move (x));
  }

  inline
  const player_passive_skill_t::projectile_name_type& player_passive_skill_t::
  projectile_name () const
  {
    return this->projectile_name_.get ();
  }

  inline
  player_passive_skill_t::projectile_name_type& player_passive_skill_t::
  projectile_name ()
  {
    return this->projectile_name_.get ();
  }

  inline
  void player_passive_skill_t::
  projectile_name (const projectile_name_type& x)
  {
    this->projectile_name_.set (x);
  }

  inline
  void player_passive_skill_t::
  projectile_name (::std::unique_ptr< projectile_name_type > x)
  {
    this->projectile_name_.set (std::move (x));
  }

  inline
  const player_passive_skill_t::projectile_particle_type& player_passive_skill_t::
  projectile_particle () const
  {
    return this->projectile_particle_.get ();
  }

  inline
  player_passive_skill_t::projectile_particle_type& player_passive_skill_t::
  projectile_particle ()
  {
    return this->projectile_particle_.get ();
  }

  inline
  void player_passive_skill_t::
  projectile_particle (const projectile_particle_type& x)
  {
    this->projectile_particle_.set (x);
  }

  inline
  void player_passive_skill_t::
  projectile_particle (::std::unique_ptr< projectile_particle_type > x)
  {
    this->projectile_particle_.set (std::move (x));
  }

  inline
  const player_passive_skill_t::projectile_sound_type& player_passive_skill_t::
  projectile_sound () const
  {
    return this->projectile_sound_.get ();
  }

  inline
  player_passive_skill_t::projectile_sound_type& player_passive_skill_t::
  projectile_sound ()
  {
    return this->projectile_sound_.get ();
  }

  inline
  void player_passive_skill_t::
  projectile_sound (const projectile_sound_type& x)
  {
    this->projectile_sound_.set (x);
  }

  inline
  void player_passive_skill_t::
  projectile_sound (::std::unique_ptr< projectile_sound_type > x)
  {
    this->projectile_sound_.set (std::move (x));
  }

  inline
  const player_passive_skill_t::projectile_starting_point_type& player_passive_skill_t::
  projectile_starting_point () const
  {
    return this->projectile_starting_point_.get ();
  }

  inline
  player_passive_skill_t::projectile_starting_point_type& player_passive_skill_t::
  projectile_starting_point ()
  {
    return this->projectile_starting_point_.get ();
  }

  inline
  void player_passive_skill_t::
  projectile_starting_point (const projectile_starting_point_type& x)
  {
    this->projectile_starting_point_.set (x);
  }

  inline
  void player_passive_skill_t::
  projectile_starting_point (::std::unique_ptr< projectile_starting_point_type > x)
  {
    this->projectile_starting_point_.set (std::move (x));
  }

  inline
  const player_passive_skill_t::projectile_end_point_type& player_passive_skill_t::
  projectile_end_point () const
  {
    return this->projectile_end_point_.get ();
  }

  inline
  player_passive_skill_t::projectile_end_point_type& player_passive_skill_t::
  projectile_end_point ()
  {
    return this->projectile_end_point_.get ();
  }

  inline
  void player_passive_skill_t::
  projectile_end_point (const projectile_end_point_type& x)
  {
    this->projectile_end_point_.set (x);
  }

  inline
  void player_passive_skill_t::
  projectile_end_point (::std::unique_ptr< projectile_end_point_type > x)
  {
    this->projectile_end_point_.set (std::move (x));
  }

  inline
  const player_passive_skill_t::projectile_trail_particle_type& player_passive_skill_t::
  projectile_trail_particle () const
  {
    return this->projectile_trail_particle_.get ();
  }

  inline
  player_passive_skill_t::projectile_trail_particle_type& player_passive_skill_t::
  projectile_trail_particle ()
  {
    return this->projectile_trail_particle_.get ();
  }

  inline
  void player_passive_skill_t::
  projectile_trail_particle (const projectile_trail_particle_type& x)
  {
    this->projectile_trail_particle_.set (x);
  }

  inline
  void player_passive_skill_t::
  projectile_trail_particle (::std::unique_ptr< projectile_trail_particle_type > x)
  {
    this->projectile_trail_particle_.set (std::move (x));
  }

  inline
  const player_passive_skill_t::projectile_light_rgb_value_type& player_passive_skill_t::
  projectile_light_rgb_value () const
  {
    return this->projectile_light_rgb_value_.get ();
  }

  inline
  player_passive_skill_t::projectile_light_rgb_value_type& player_passive_skill_t::
  projectile_light_rgb_value ()
  {
    return this->projectile_light_rgb_value_.get ();
  }

  inline
  void player_passive_skill_t::
  projectile_light_rgb_value (const projectile_light_rgb_value_type& x)
  {
    this->projectile_light_rgb_value_.set (x);
  }

  inline
  void player_passive_skill_t::
  projectile_light_rgb_value (::std::unique_ptr< projectile_light_rgb_value_type > x)
  {
    this->projectile_light_rgb_value_.set (std::move (x));
  }

  inline
  const player_passive_skill_t::projectile_light_value_type& player_passive_skill_t::
  projectile_light_value () const
  {
    return this->projectile_light_value_.get ();
  }

  inline
  player_passive_skill_t::projectile_light_value_type& player_passive_skill_t::
  projectile_light_value ()
  {
    return this->projectile_light_value_.get ();
  }

  inline
  void player_passive_skill_t::
  projectile_light_value (const projectile_light_value_type& x)
  {
    this->projectile_light_value_.set (x);
  }

  inline
  const player_passive_skill_t::projectile_light_range_value_type& player_passive_skill_t::
  projectile_light_range_value () const
  {
    return this->projectile_light_range_value_.get ();
  }

  inline
  player_passive_skill_t::projectile_light_range_value_type& player_passive_skill_t::
  projectile_light_range_value ()
  {
    return this->projectile_light_range_value_.get ();
  }

  inline
  void player_passive_skill_t::
  projectile_light_range_value (const projectile_light_range_value_type& x)
  {
    this->projectile_light_range_value_.set (x);
  }


  // player_passive_skill_table
  // 

  inline
  const player_passive_skill_table::player_passive_skill_template_sequence& player_passive_skill_table::
  player_passive_skill_template () const
  {
    return this->player_passive_skill_template_;
  }

  inline
  player_passive_skill_table::player_passive_skill_template_sequence& player_passive_skill_table::
  player_passive_skill_template ()
  {
    return this->player_passive_skill_template_;
  }

  inline
  void player_passive_skill_table::
  player_passive_skill_template (const player_passive_skill_template_sequence& s)
  {
    this->player_passive_skill_template_ = s;
  }
}

// Begin epilogue.
//
//
// End epilogue.

#endif // GDT_PLAYER_PASSIVE_SKILL_TABLE_IXX
