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

#ifndef GDT_EQUIP_TABLE_IXX
#define GDT_EQUIP_TABLE_IXX

// Begin prologue.
//
//
// End prologue.

#include "shared_types.ixx"

namespace gdt
{
  // equip_t
  // 

  inline
  const equip_t::item_code_type& equip_t::
  item_code () const
  {
    return this->item_code_.get ();
  }

  inline
  equip_t::item_code_type& equip_t::
  item_code ()
  {
    return this->item_code_.get ();
  }

  inline
  void equip_t::
  item_code (const item_code_type& x)
  {
    this->item_code_.set (x);
  }

  inline
  void equip_t::
  item_code (::std::unique_ptr< item_code_type > x)
  {
    this->item_code_.set (std::move (x));
  }

  inline
  const equip_t::min_level_type& equip_t::
  min_level () const
  {
    return this->min_level_.get ();
  }

  inline
  equip_t::min_level_type& equip_t::
  min_level ()
  {
    return this->min_level_.get ();
  }

  inline
  void equip_t::
  min_level (const min_level_type& x)
  {
    this->min_level_.set (x);
  }

  inline
  const equip_t::item_grade_type& equip_t::
  item_grade () const
  {
    return this->item_grade_.get ();
  }

  inline
  equip_t::item_grade_type& equip_t::
  item_grade ()
  {
    return this->item_grade_.get ();
  }

  inline
  void equip_t::
  item_grade (const item_grade_type& x)
  {
    this->item_grade_.set (x);
  }

  inline
  const equip_t::item_enchant_level_type& equip_t::
  item_enchant_level () const
  {
    return this->item_enchant_level_.get ();
  }

  inline
  equip_t::item_enchant_level_type& equip_t::
  item_enchant_level ()
  {
    return this->item_enchant_level_.get ();
  }

  inline
  void equip_t::
  item_enchant_level (const item_enchant_level_type& x)
  {
    this->item_enchant_level_.set (x);
  }

  inline
  const equip_t::equip_part_type& equip_t::
  equip_part () const
  {
    return this->equip_part_.get ();
  }

  inline
  equip_t::equip_part_type& equip_t::
  equip_part ()
  {
    return this->equip_part_.get ();
  }

  inline
  void equip_t::
  equip_part (const equip_part_type& x)
  {
    this->equip_part_.set (x);
  }

  inline
  const equip_t::equip_type_type& equip_t::
  equip_type () const
  {
    return this->equip_type_.get ();
  }

  inline
  equip_t::equip_type_type& equip_t::
  equip_type ()
  {
    return this->equip_type_.get ();
  }

  inline
  void equip_t::
  equip_type (const equip_type_type& x)
  {
    this->equip_type_.set (x);
  }

  inline
  const equip_t::material_type_type& equip_t::
  material_type () const
  {
    return this->material_type_.get ();
  }

  inline
  equip_t::material_type_type& equip_t::
  material_type ()
  {
    return this->material_type_.get ();
  }

  inline
  void equip_t::
  material_type (const material_type_type& x)
  {
    this->material_type_.set (x);
  }

  inline
  const equip_t::looting_mil_sec_type& equip_t::
  looting_mil_sec () const
  {
    return this->looting_mil_sec_.get ();
  }

  inline
  equip_t::looting_mil_sec_type& equip_t::
  looting_mil_sec ()
  {
    return this->looting_mil_sec_.get ();
  }

  inline
  void equip_t::
  looting_mil_sec (const looting_mil_sec_type& x)
  {
    this->looting_mil_sec_.set (x);
  }

  inline
  const equip_t::apply_script_1_type& equip_t::
  apply_script_1 () const
  {
    return this->apply_script_1_.get ();
  }

  inline
  equip_t::apply_script_1_type& equip_t::
  apply_script_1 ()
  {
    return this->apply_script_1_.get ();
  }

  inline
  void equip_t::
  apply_script_1 (const apply_script_1_type& x)
  {
    this->apply_script_1_.set (x);
  }

  inline
  const equip_t::apply_value_1_type& equip_t::
  apply_value_1 () const
  {
    return this->apply_value_1_.get ();
  }

  inline
  equip_t::apply_value_1_type& equip_t::
  apply_value_1 ()
  {
    return this->apply_value_1_.get ();
  }

  inline
  void equip_t::
  apply_value_1 (const apply_value_1_type& x)
  {
    this->apply_value_1_.set (x);
  }

  inline
  const equip_t::apply_script_2_type& equip_t::
  apply_script_2 () const
  {
    return this->apply_script_2_.get ();
  }

  inline
  equip_t::apply_script_2_type& equip_t::
  apply_script_2 ()
  {
    return this->apply_script_2_.get ();
  }

  inline
  void equip_t::
  apply_script_2 (const apply_script_2_type& x)
  {
    this->apply_script_2_.set (x);
  }

  inline
  const equip_t::apply_value_2_type& equip_t::
  apply_value_2 () const
  {
    return this->apply_value_2_.get ();
  }

  inline
  equip_t::apply_value_2_type& equip_t::
  apply_value_2 ()
  {
    return this->apply_value_2_.get ();
  }

  inline
  void equip_t::
  apply_value_2 (const apply_value_2_type& x)
  {
    this->apply_value_2_.set (x);
  }

  inline
  const equip_t::apply_script_3_type& equip_t::
  apply_script_3 () const
  {
    return this->apply_script_3_.get ();
  }

  inline
  equip_t::apply_script_3_type& equip_t::
  apply_script_3 ()
  {
    return this->apply_script_3_.get ();
  }

  inline
  void equip_t::
  apply_script_3 (const apply_script_3_type& x)
  {
    this->apply_script_3_.set (x);
  }

  inline
  const equip_t::apply_value_3_type& equip_t::
  apply_value_3 () const
  {
    return this->apply_value_3_.get ();
  }

  inline
  equip_t::apply_value_3_type& equip_t::
  apply_value_3 ()
  {
    return this->apply_value_3_.get ();
  }

  inline
  void equip_t::
  apply_value_3 (const apply_value_3_type& x)
  {
    this->apply_value_3_.set (x);
  }

  inline
  const equip_t::apply_script_4_type& equip_t::
  apply_script_4 () const
  {
    return this->apply_script_4_.get ();
  }

  inline
  equip_t::apply_script_4_type& equip_t::
  apply_script_4 ()
  {
    return this->apply_script_4_.get ();
  }

  inline
  void equip_t::
  apply_script_4 (const apply_script_4_type& x)
  {
    this->apply_script_4_.set (x);
  }

  inline
  const equip_t::apply_value_4_type& equip_t::
  apply_value_4 () const
  {
    return this->apply_value_4_.get ();
  }

  inline
  equip_t::apply_value_4_type& equip_t::
  apply_value_4 ()
  {
    return this->apply_value_4_.get ();
  }

  inline
  void equip_t::
  apply_value_4 (const apply_value_4_type& x)
  {
    this->apply_value_4_.set (x);
  }

  inline
  const equip_t::item_suffix_id_type& equip_t::
  item_suffix_id () const
  {
    return this->item_suffix_id_.get ();
  }

  inline
  equip_t::item_suffix_id_type& equip_t::
  item_suffix_id ()
  {
    return this->item_suffix_id_.get ();
  }

  inline
  void equip_t::
  item_suffix_id (const item_suffix_id_type& x)
  {
    this->item_suffix_id_.set (x);
  }

  inline
  const equip_t::min_socket_count_type& equip_t::
  min_socket_count () const
  {
    return this->min_socket_count_.get ();
  }

  inline
  equip_t::min_socket_count_type& equip_t::
  min_socket_count ()
  {
    return this->min_socket_count_.get ();
  }

  inline
  void equip_t::
  min_socket_count (const min_socket_count_type& x)
  {
    this->min_socket_count_.set (x);
  }

  inline
  const equip_t::max_socket_count_type& equip_t::
  max_socket_count () const
  {
    return this->max_socket_count_.get ();
  }

  inline
  equip_t::max_socket_count_type& equip_t::
  max_socket_count ()
  {
    return this->max_socket_count_.get ();
  }

  inline
  void equip_t::
  max_socket_count (const max_socket_count_type& x)
  {
    this->max_socket_count_.set (x);
  }

  inline
  const equip_t::fragment_code_type& equip_t::
  fragment_code () const
  {
    return this->fragment_code_.get ();
  }

  inline
  equip_t::fragment_code_type& equip_t::
  fragment_code ()
  {
    return this->fragment_code_.get ();
  }

  inline
  void equip_t::
  fragment_code (const fragment_code_type& x)
  {
    this->fragment_code_.set (x);
  }

  inline
  void equip_t::
  fragment_code (::std::unique_ptr< fragment_code_type > x)
  {
    this->fragment_code_.set (std::move (x));
  }

  inline
  const equip_t::upgrade_rate_type& equip_t::
  upgrade_rate () const
  {
    return this->upgrade_rate_.get ();
  }

  inline
  equip_t::upgrade_rate_type& equip_t::
  upgrade_rate ()
  {
    return this->upgrade_rate_.get ();
  }

  inline
  void equip_t::
  upgrade_rate (const upgrade_rate_type& x)
  {
    this->upgrade_rate_.set (x);
  }

  inline
  const equip_t::need_upgrade_item_code_type& equip_t::
  need_upgrade_item_code () const
  {
    return this->need_upgrade_item_code_.get ();
  }

  inline
  equip_t::need_upgrade_item_code_type& equip_t::
  need_upgrade_item_code ()
  {
    return this->need_upgrade_item_code_.get ();
  }

  inline
  void equip_t::
  need_upgrade_item_code (const need_upgrade_item_code_type& x)
  {
    this->need_upgrade_item_code_.set (x);
  }

  inline
  const equip_t::need_upgrade_item_count_type& equip_t::
  need_upgrade_item_count () const
  {
    return this->need_upgrade_item_count_.get ();
  }

  inline
  equip_t::need_upgrade_item_count_type& equip_t::
  need_upgrade_item_count ()
  {
    return this->need_upgrade_item_count_.get ();
  }

  inline
  void equip_t::
  need_upgrade_item_count (const need_upgrade_item_count_type& x)
  {
    this->need_upgrade_item_count_.set (x);
  }

  inline
  const equip_t::use_revision_upgrade_rate_item_type& equip_t::
  use_revision_upgrade_rate_item () const
  {
    return this->use_revision_upgrade_rate_item_.get ();
  }

  inline
  equip_t::use_revision_upgrade_rate_item_type& equip_t::
  use_revision_upgrade_rate_item ()
  {
    return this->use_revision_upgrade_rate_item_.get ();
  }

  inline
  void equip_t::
  use_revision_upgrade_rate_item (const use_revision_upgrade_rate_item_type& x)
  {
    this->use_revision_upgrade_rate_item_.set (x);
  }

  inline
  const equip_t::pre_upgrade_code_type& equip_t::
  pre_upgrade_code () const
  {
    return this->pre_upgrade_code_.get ();
  }

  inline
  equip_t::pre_upgrade_code_type& equip_t::
  pre_upgrade_code ()
  {
    return this->pre_upgrade_code_.get ();
  }

  inline
  void equip_t::
  pre_upgrade_code (const pre_upgrade_code_type& x)
  {
    this->pre_upgrade_code_.set (x);
  }

  inline
  void equip_t::
  pre_upgrade_code (::std::unique_ptr< pre_upgrade_code_type > x)
  {
    this->pre_upgrade_code_.set (std::move (x));
  }

  inline
  const equip_t::next_upgrade_code_type& equip_t::
  next_upgrade_code () const
  {
    return this->next_upgrade_code_.get ();
  }

  inline
  equip_t::next_upgrade_code_type& equip_t::
  next_upgrade_code ()
  {
    return this->next_upgrade_code_.get ();
  }

  inline
  void equip_t::
  next_upgrade_code (const next_upgrade_code_type& x)
  {
    this->next_upgrade_code_.set (x);
  }

  inline
  void equip_t::
  next_upgrade_code (::std::unique_ptr< next_upgrade_code_type > x)
  {
    this->next_upgrade_code_.set (std::move (x));
  }

  inline
  const equip_t::sell_cost_type_type& equip_t::
  sell_cost_type () const
  {
    return this->sell_cost_type_.get ();
  }

  inline
  equip_t::sell_cost_type_type& equip_t::
  sell_cost_type ()
  {
    return this->sell_cost_type_.get ();
  }

  inline
  void equip_t::
  sell_cost_type (const sell_cost_type_type& x)
  {
    this->sell_cost_type_.set (x);
  }

  inline
  void equip_t::
  sell_cost_type (::std::unique_ptr< sell_cost_type_type > x)
  {
    this->sell_cost_type_.set (std::move (x));
  }

  inline
  const equip_t::sell_cost_type1& equip_t::
  sell_cost () const
  {
    return this->sell_cost_.get ();
  }

  inline
  equip_t::sell_cost_type1& equip_t::
  sell_cost ()
  {
    return this->sell_cost_.get ();
  }

  inline
  void equip_t::
  sell_cost (const sell_cost_type1& x)
  {
    this->sell_cost_.set (x);
  }

  inline
  const equip_t::buy_cost_type_1_type& equip_t::
  buy_cost_type_1 () const
  {
    return this->buy_cost_type_1_.get ();
  }

  inline
  equip_t::buy_cost_type_1_type& equip_t::
  buy_cost_type_1 ()
  {
    return this->buy_cost_type_1_.get ();
  }

  inline
  void equip_t::
  buy_cost_type_1 (const buy_cost_type_1_type& x)
  {
    this->buy_cost_type_1_.set (x);
  }

  inline
  void equip_t::
  buy_cost_type_1 (::std::unique_ptr< buy_cost_type_1_type > x)
  {
    this->buy_cost_type_1_.set (std::move (x));
  }

  inline
  const equip_t::buy_cost_1_type& equip_t::
  buy_cost_1 () const
  {
    return this->buy_cost_1_.get ();
  }

  inline
  equip_t::buy_cost_1_type& equip_t::
  buy_cost_1 ()
  {
    return this->buy_cost_1_.get ();
  }

  inline
  void equip_t::
  buy_cost_1 (const buy_cost_1_type& x)
  {
    this->buy_cost_1_.set (x);
  }

  inline
  const equip_t::buy_cost_type_2_type& equip_t::
  buy_cost_type_2 () const
  {
    return this->buy_cost_type_2_.get ();
  }

  inline
  equip_t::buy_cost_type_2_type& equip_t::
  buy_cost_type_2 ()
  {
    return this->buy_cost_type_2_.get ();
  }

  inline
  void equip_t::
  buy_cost_type_2 (const buy_cost_type_2_type& x)
  {
    this->buy_cost_type_2_.set (x);
  }

  inline
  void equip_t::
  buy_cost_type_2 (::std::unique_ptr< buy_cost_type_2_type > x)
  {
    this->buy_cost_type_2_.set (std::move (x));
  }

  inline
  const equip_t::buy_cost_2_type& equip_t::
  buy_cost_2 () const
  {
    return this->buy_cost_2_.get ();
  }

  inline
  equip_t::buy_cost_2_type& equip_t::
  buy_cost_2 ()
  {
    return this->buy_cost_2_.get ();
  }

  inline
  void equip_t::
  buy_cost_2 (const buy_cost_2_type& x)
  {
    this->buy_cost_2_.set (x);
  }

  inline
  const equip_t::wear_type_type& equip_t::
  wear_type () const
  {
    return this->wear_type_.get ();
  }

  inline
  equip_t::wear_type_type& equip_t::
  wear_type ()
  {
    return this->wear_type_.get ();
  }

  inline
  void equip_t::
  wear_type (const wear_type_type& x)
  {
    this->wear_type_.set (x);
  }

  inline
  const equip_t::mount_point_type& equip_t::
  mount_point () const
  {
    return this->mount_point_.get ();
  }

  inline
  equip_t::mount_point_type& equip_t::
  mount_point ()
  {
    return this->mount_point_.get ();
  }

  inline
  void equip_t::
  mount_point (const mount_point_type& x)
  {
    this->mount_point_.set (x);
  }

  inline
  const equip_t::unmount_point_type& equip_t::
  unmount_point () const
  {
    return this->unmount_point_.get ();
  }

  inline
  equip_t::unmount_point_type& equip_t::
  unmount_point ()
  {
    return this->unmount_point_.get ();
  }

  inline
  void equip_t::
  unmount_point (const unmount_point_type& x)
  {
    this->unmount_point_.set (x);
  }

  inline
  const equip_t::modeling_name_type& equip_t::
  modeling_name () const
  {
    return this->modeling_name_.get ();
  }

  inline
  equip_t::modeling_name_type& equip_t::
  modeling_name ()
  {
    return this->modeling_name_.get ();
  }

  inline
  void equip_t::
  modeling_name (const modeling_name_type& x)
  {
    this->modeling_name_.set (x);
  }

  inline
  void equip_t::
  modeling_name (::std::unique_ptr< modeling_name_type > x)
  {
    this->modeling_name_.set (std::move (x));
  }

  inline
  const equip_t::effect_name_type& equip_t::
  effect_name () const
  {
    return this->effect_name_.get ();
  }

  inline
  equip_t::effect_name_type& equip_t::
  effect_name ()
  {
    return this->effect_name_.get ();
  }

  inline
  void equip_t::
  effect_name (const effect_name_type& x)
  {
    this->effect_name_.set (x);
  }

  inline
  void equip_t::
  effect_name (::std::unique_ptr< effect_name_type > x)
  {
    this->effect_name_.set (std::move (x));
  }

  inline
  const equip_t::material_name_type& equip_t::
  material_name () const
  {
    return this->material_name_.get ();
  }

  inline
  equip_t::material_name_type& equip_t::
  material_name ()
  {
    return this->material_name_.get ();
  }

  inline
  void equip_t::
  material_name (const material_name_type& x)
  {
    this->material_name_.set (x);
  }

  inline
  void equip_t::
  material_name (::std::unique_ptr< material_name_type > x)
  {
    this->material_name_.set (std::move (x));
  }

  inline
  const equip_t::base_trail_name_type& equip_t::
  base_trail_name () const
  {
    return this->base_trail_name_.get ();
  }

  inline
  equip_t::base_trail_name_type& equip_t::
  base_trail_name ()
  {
    return this->base_trail_name_.get ();
  }

  inline
  void equip_t::
  base_trail_name (const base_trail_name_type& x)
  {
    this->base_trail_name_.set (x);
  }

  inline
  void equip_t::
  base_trail_name (::std::unique_ptr< base_trail_name_type > x)
  {
    this->base_trail_name_.set (std::move (x));
  }

  inline
  const equip_t::icon_name_type& equip_t::
  icon_name () const
  {
    return this->icon_name_.get ();
  }

  inline
  equip_t::icon_name_type& equip_t::
  icon_name ()
  {
    return this->icon_name_.get ();
  }

  inline
  void equip_t::
  icon_name (const icon_name_type& x)
  {
    this->icon_name_.set (x);
  }

  inline
  void equip_t::
  icon_name (::std::unique_ptr< icon_name_type > x)
  {
    this->icon_name_.set (std::move (x));
  }


  // equip_table
  // 

  inline
  const equip_table::equip_template_sequence& equip_table::
  equip_template () const
  {
    return this->equip_template_;
  }

  inline
  equip_table::equip_template_sequence& equip_table::
  equip_template ()
  {
    return this->equip_template_;
  }

  inline
  void equip_table::
  equip_template (const equip_template_sequence& s)
  {
    this->equip_template_ = s;
  }
}

// Begin epilogue.
//
//
// End epilogue.

#endif // GDT_EQUIP_TABLE_IXX