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

#ifndef GDT_SKILL_EFFECT_TABLE_IXX
#define GDT_SKILL_EFFECT_TABLE_IXX

// Begin prologue.
//
//
// End prologue.

#include "shared_types.ixx"

namespace gdt
{
  // skill_effect_t
  // 

  inline
  const skill_effect_t::skill_effect_index_type& skill_effect_t::
  skill_effect_index () const
  {
    return this->skill_effect_index_.get ();
  }

  inline
  skill_effect_t::skill_effect_index_type& skill_effect_t::
  skill_effect_index ()
  {
    return this->skill_effect_index_.get ();
  }

  inline
  void skill_effect_t::
  skill_effect_index (const skill_effect_index_type& x)
  {
    this->skill_effect_index_.set (x);
  }

  inline
  const skill_effect_t::targeting_type_type& skill_effect_t::
  targeting_type () const
  {
    return this->targeting_type_.get ();
  }

  inline
  skill_effect_t::targeting_type_type& skill_effect_t::
  targeting_type ()
  {
    return this->targeting_type_.get ();
  }

  inline
  void skill_effect_t::
  targeting_type (const targeting_type_type& x)
  {
    this->targeting_type_.set (x);
  }

  inline
  void skill_effect_t::
  targeting_type (::std::unique_ptr< targeting_type_type > x)
  {
    this->targeting_type_.set (std::move (x));
  }

  inline
  const skill_effect_t::available_target_type& skill_effect_t::
  available_target () const
  {
    return this->available_target_.get ();
  }

  inline
  skill_effect_t::available_target_type& skill_effect_t::
  available_target ()
  {
    return this->available_target_.get ();
  }

  inline
  void skill_effect_t::
  available_target (const available_target_type& x)
  {
    this->available_target_.set (x);
  }

  inline
  const skill_effect_t::except_target_type& skill_effect_t::
  except_target () const
  {
    return this->except_target_.get ();
  }

  inline
  skill_effect_t::except_target_type& skill_effect_t::
  except_target ()
  {
    return this->except_target_.get ();
  }

  inline
  void skill_effect_t::
  except_target (const except_target_type& x)
  {
    this->except_target_.set (x);
  }

  inline
  const skill_effect_t::target_direction_type& skill_effect_t::
  target_direction () const
  {
    return this->target_direction_.get ();
  }

  inline
  skill_effect_t::target_direction_type& skill_effect_t::
  target_direction ()
  {
    return this->target_direction_.get ();
  }

  inline
  void skill_effect_t::
  target_direction (const target_direction_type& x)
  {
    this->target_direction_.set (x);
  }

  inline
  void skill_effect_t::
  target_direction (::std::unique_ptr< target_direction_type > x)
  {
    this->target_direction_.set (std::move (x));
  }

  inline
  const skill_effect_t::target_orientation_type& skill_effect_t::
  target_orientation () const
  {
    return this->target_orientation_.get ();
  }

  inline
  skill_effect_t::target_orientation_type& skill_effect_t::
  target_orientation ()
  {
    return this->target_orientation_.get ();
  }

  inline
  void skill_effect_t::
  target_orientation (const target_orientation_type& x)
  {
    this->target_orientation_.set (x);
  }

  inline
  void skill_effect_t::
  target_orientation (::std::unique_ptr< target_orientation_type > x)
  {
    this->target_orientation_.set (std::move (x));
  }

  inline
  const skill_effect_t::effect_range_direction_type& skill_effect_t::
  effect_range_direction () const
  {
    return this->effect_range_direction_.get ();
  }

  inline
  skill_effect_t::effect_range_direction_type& skill_effect_t::
  effect_range_direction ()
  {
    return this->effect_range_direction_.get ();
  }

  inline
  void skill_effect_t::
  effect_range_direction (const effect_range_direction_type& x)
  {
    this->effect_range_direction_.set (x);
  }

  inline
  const skill_effect_t::effect_range_value_type& skill_effect_t::
  effect_range_value () const
  {
    return this->effect_range_value_.get ();
  }

  inline
  skill_effect_t::effect_range_value_type& skill_effect_t::
  effect_range_value ()
  {
    return this->effect_range_value_.get ();
  }

  inline
  void skill_effect_t::
  effect_range_value (const effect_range_value_type& x)
  {
    this->effect_range_value_.set (x);
  }

  inline
  const skill_effect_t::attack_attribute_type& skill_effect_t::
  attack_attribute () const
  {
    return this->attack_attribute_.get ();
  }

  inline
  skill_effect_t::attack_attribute_type& skill_effect_t::
  attack_attribute ()
  {
    return this->attack_attribute_.get ();
  }

  inline
  void skill_effect_t::
  attack_attribute (const attack_attribute_type& x)
  {
    this->attack_attribute_.set (x);
  }

  inline
  const skill_effect_t::effect_stack_category_type& skill_effect_t::
  effect_stack_category () const
  {
    return this->effect_stack_category_.get ();
  }

  inline
  skill_effect_t::effect_stack_category_type& skill_effect_t::
  effect_stack_category ()
  {
    return this->effect_stack_category_.get ();
  }

  inline
  void skill_effect_t::
  effect_stack_category (const effect_stack_category_type& x)
  {
    this->effect_stack_category_.set (x);
  }

  inline
  const skill_effect_t::caster_should_critical_1_type& skill_effect_t::
  caster_should_critical_1 () const
  {
    return this->caster_should_critical_1_.get ();
  }

  inline
  skill_effect_t::caster_should_critical_1_type& skill_effect_t::
  caster_should_critical_1 ()
  {
    return this->caster_should_critical_1_.get ();
  }

  inline
  void skill_effect_t::
  caster_should_critical_1 (const caster_should_critical_1_type& x)
  {
    this->caster_should_critical_1_.set (x);
  }

  inline
  const skill_effect_t::caster_effect_script_1_type& skill_effect_t::
  caster_effect_script_1 () const
  {
    return this->caster_effect_script_1_.get ();
  }

  inline
  skill_effect_t::caster_effect_script_1_type& skill_effect_t::
  caster_effect_script_1 ()
  {
    return this->caster_effect_script_1_.get ();
  }

  inline
  void skill_effect_t::
  caster_effect_script_1 (const caster_effect_script_1_type& x)
  {
    this->caster_effect_script_1_.set (x);
  }

  inline
  void skill_effect_t::
  caster_effect_script_1 (::std::unique_ptr< caster_effect_script_1_type > x)
  {
    this->caster_effect_script_1_.set (std::move (x));
  }

  inline
  const skill_effect_t::caster_use_target_status_type_1_type& skill_effect_t::
  caster_use_target_status_type_1 () const
  {
    return this->caster_use_target_status_type_1_.get ();
  }

  inline
  skill_effect_t::caster_use_target_status_type_1_type& skill_effect_t::
  caster_use_target_status_type_1 ()
  {
    return this->caster_use_target_status_type_1_.get ();
  }

  inline
  void skill_effect_t::
  caster_use_target_status_type_1 (const caster_use_target_status_type_1_type& x)
  {
    this->caster_use_target_status_type_1_.set (x);
  }

  inline
  void skill_effect_t::
  caster_use_target_status_type_1 (::std::unique_ptr< caster_use_target_status_type_1_type > x)
  {
    this->caster_use_target_status_type_1_.set (std::move (x));
  }

  inline
  const skill_effect_t::caster_effect_value_percent_1_type& skill_effect_t::
  caster_effect_value_percent_1 () const
  {
    return this->caster_effect_value_percent_1_.get ();
  }

  inline
  skill_effect_t::caster_effect_value_percent_1_type& skill_effect_t::
  caster_effect_value_percent_1 ()
  {
    return this->caster_effect_value_percent_1_.get ();
  }

  inline
  void skill_effect_t::
  caster_effect_value_percent_1 (const caster_effect_value_percent_1_type& x)
  {
    this->caster_effect_value_percent_1_.set (x);
  }

  inline
  const skill_effect_t::caster_usable_status_type_1_type& skill_effect_t::
  caster_usable_status_type_1 () const
  {
    return this->caster_usable_status_type_1_.get ();
  }

  inline
  skill_effect_t::caster_usable_status_type_1_type& skill_effect_t::
  caster_usable_status_type_1 ()
  {
    return this->caster_usable_status_type_1_.get ();
  }

  inline
  void skill_effect_t::
  caster_usable_status_type_1 (const caster_usable_status_type_1_type& x)
  {
    this->caster_usable_status_type_1_.set (x);
  }

  inline
  void skill_effect_t::
  caster_usable_status_type_1 (::std::unique_ptr< caster_usable_status_type_1_type > x)
  {
    this->caster_usable_status_type_1_.set (std::move (x));
  }

  inline
  const skill_effect_t::caster_should_critical_2_type& skill_effect_t::
  caster_should_critical_2 () const
  {
    return this->caster_should_critical_2_.get ();
  }

  inline
  skill_effect_t::caster_should_critical_2_type& skill_effect_t::
  caster_should_critical_2 ()
  {
    return this->caster_should_critical_2_.get ();
  }

  inline
  void skill_effect_t::
  caster_should_critical_2 (const caster_should_critical_2_type& x)
  {
    this->caster_should_critical_2_.set (x);
  }

  inline
  const skill_effect_t::caster_effect_script_2_type& skill_effect_t::
  caster_effect_script_2 () const
  {
    return this->caster_effect_script_2_.get ();
  }

  inline
  skill_effect_t::caster_effect_script_2_type& skill_effect_t::
  caster_effect_script_2 ()
  {
    return this->caster_effect_script_2_.get ();
  }

  inline
  void skill_effect_t::
  caster_effect_script_2 (const caster_effect_script_2_type& x)
  {
    this->caster_effect_script_2_.set (x);
  }

  inline
  void skill_effect_t::
  caster_effect_script_2 (::std::unique_ptr< caster_effect_script_2_type > x)
  {
    this->caster_effect_script_2_.set (std::move (x));
  }

  inline
  const skill_effect_t::caster_use_target_status_type_2_type& skill_effect_t::
  caster_use_target_status_type_2 () const
  {
    return this->caster_use_target_status_type_2_.get ();
  }

  inline
  skill_effect_t::caster_use_target_status_type_2_type& skill_effect_t::
  caster_use_target_status_type_2 ()
  {
    return this->caster_use_target_status_type_2_.get ();
  }

  inline
  void skill_effect_t::
  caster_use_target_status_type_2 (const caster_use_target_status_type_2_type& x)
  {
    this->caster_use_target_status_type_2_.set (x);
  }

  inline
  void skill_effect_t::
  caster_use_target_status_type_2 (::std::unique_ptr< caster_use_target_status_type_2_type > x)
  {
    this->caster_use_target_status_type_2_.set (std::move (x));
  }

  inline
  const skill_effect_t::caster_effect_value_percent_2_type& skill_effect_t::
  caster_effect_value_percent_2 () const
  {
    return this->caster_effect_value_percent_2_.get ();
  }

  inline
  skill_effect_t::caster_effect_value_percent_2_type& skill_effect_t::
  caster_effect_value_percent_2 ()
  {
    return this->caster_effect_value_percent_2_.get ();
  }

  inline
  void skill_effect_t::
  caster_effect_value_percent_2 (const caster_effect_value_percent_2_type& x)
  {
    this->caster_effect_value_percent_2_.set (x);
  }

  inline
  const skill_effect_t::caster_usable_status_type_2_type& skill_effect_t::
  caster_usable_status_type_2 () const
  {
    return this->caster_usable_status_type_2_.get ();
  }

  inline
  skill_effect_t::caster_usable_status_type_2_type& skill_effect_t::
  caster_usable_status_type_2 ()
  {
    return this->caster_usable_status_type_2_.get ();
  }

  inline
  void skill_effect_t::
  caster_usable_status_type_2 (const caster_usable_status_type_2_type& x)
  {
    this->caster_usable_status_type_2_.set (x);
  }

  inline
  void skill_effect_t::
  caster_usable_status_type_2 (::std::unique_ptr< caster_usable_status_type_2_type > x)
  {
    this->caster_usable_status_type_2_.set (std::move (x));
  }

  inline
  const skill_effect_t::castee_should_critical_1_type& skill_effect_t::
  castee_should_critical_1 () const
  {
    return this->castee_should_critical_1_.get ();
  }

  inline
  skill_effect_t::castee_should_critical_1_type& skill_effect_t::
  castee_should_critical_1 ()
  {
    return this->castee_should_critical_1_.get ();
  }

  inline
  void skill_effect_t::
  castee_should_critical_1 (const castee_should_critical_1_type& x)
  {
    this->castee_should_critical_1_.set (x);
  }

  inline
  const skill_effect_t::castee_effect_script_1_type& skill_effect_t::
  castee_effect_script_1 () const
  {
    return this->castee_effect_script_1_.get ();
  }

  inline
  skill_effect_t::castee_effect_script_1_type& skill_effect_t::
  castee_effect_script_1 ()
  {
    return this->castee_effect_script_1_.get ();
  }

  inline
  void skill_effect_t::
  castee_effect_script_1 (const castee_effect_script_1_type& x)
  {
    this->castee_effect_script_1_.set (x);
  }

  inline
  void skill_effect_t::
  castee_effect_script_1 (::std::unique_ptr< castee_effect_script_1_type > x)
  {
    this->castee_effect_script_1_.set (std::move (x));
  }

  inline
  const skill_effect_t::castee_use_target_status_type_1_type& skill_effect_t::
  castee_use_target_status_type_1 () const
  {
    return this->castee_use_target_status_type_1_.get ();
  }

  inline
  skill_effect_t::castee_use_target_status_type_1_type& skill_effect_t::
  castee_use_target_status_type_1 ()
  {
    return this->castee_use_target_status_type_1_.get ();
  }

  inline
  void skill_effect_t::
  castee_use_target_status_type_1 (const castee_use_target_status_type_1_type& x)
  {
    this->castee_use_target_status_type_1_.set (x);
  }

  inline
  void skill_effect_t::
  castee_use_target_status_type_1 (::std::unique_ptr< castee_use_target_status_type_1_type > x)
  {
    this->castee_use_target_status_type_1_.set (std::move (x));
  }

  inline
  const skill_effect_t::castee_effect_value_percent_1_type& skill_effect_t::
  castee_effect_value_percent_1 () const
  {
    return this->castee_effect_value_percent_1_.get ();
  }

  inline
  skill_effect_t::castee_effect_value_percent_1_type& skill_effect_t::
  castee_effect_value_percent_1 ()
  {
    return this->castee_effect_value_percent_1_.get ();
  }

  inline
  void skill_effect_t::
  castee_effect_value_percent_1 (const castee_effect_value_percent_1_type& x)
  {
    this->castee_effect_value_percent_1_.set (x);
  }

  inline
  const skill_effect_t::castee_usable_status_type_1_type& skill_effect_t::
  castee_usable_status_type_1 () const
  {
    return this->castee_usable_status_type_1_.get ();
  }

  inline
  skill_effect_t::castee_usable_status_type_1_type& skill_effect_t::
  castee_usable_status_type_1 ()
  {
    return this->castee_usable_status_type_1_.get ();
  }

  inline
  void skill_effect_t::
  castee_usable_status_type_1 (const castee_usable_status_type_1_type& x)
  {
    this->castee_usable_status_type_1_.set (x);
  }

  inline
  void skill_effect_t::
  castee_usable_status_type_1 (::std::unique_ptr< castee_usable_status_type_1_type > x)
  {
    this->castee_usable_status_type_1_.set (std::move (x));
  }

  inline
  const skill_effect_t::castee_should_critical_2_type& skill_effect_t::
  castee_should_critical_2 () const
  {
    return this->castee_should_critical_2_.get ();
  }

  inline
  skill_effect_t::castee_should_critical_2_type& skill_effect_t::
  castee_should_critical_2 ()
  {
    return this->castee_should_critical_2_.get ();
  }

  inline
  void skill_effect_t::
  castee_should_critical_2 (const castee_should_critical_2_type& x)
  {
    this->castee_should_critical_2_.set (x);
  }

  inline
  const skill_effect_t::castee_effect_script_2_type& skill_effect_t::
  castee_effect_script_2 () const
  {
    return this->castee_effect_script_2_.get ();
  }

  inline
  skill_effect_t::castee_effect_script_2_type& skill_effect_t::
  castee_effect_script_2 ()
  {
    return this->castee_effect_script_2_.get ();
  }

  inline
  void skill_effect_t::
  castee_effect_script_2 (const castee_effect_script_2_type& x)
  {
    this->castee_effect_script_2_.set (x);
  }

  inline
  void skill_effect_t::
  castee_effect_script_2 (::std::unique_ptr< castee_effect_script_2_type > x)
  {
    this->castee_effect_script_2_.set (std::move (x));
  }

  inline
  const skill_effect_t::castee_use_target_status_type_2_type& skill_effect_t::
  castee_use_target_status_type_2 () const
  {
    return this->castee_use_target_status_type_2_.get ();
  }

  inline
  skill_effect_t::castee_use_target_status_type_2_type& skill_effect_t::
  castee_use_target_status_type_2 ()
  {
    return this->castee_use_target_status_type_2_.get ();
  }

  inline
  void skill_effect_t::
  castee_use_target_status_type_2 (const castee_use_target_status_type_2_type& x)
  {
    this->castee_use_target_status_type_2_.set (x);
  }

  inline
  void skill_effect_t::
  castee_use_target_status_type_2 (::std::unique_ptr< castee_use_target_status_type_2_type > x)
  {
    this->castee_use_target_status_type_2_.set (std::move (x));
  }

  inline
  const skill_effect_t::castee_effect_value_percent_2_type& skill_effect_t::
  castee_effect_value_percent_2 () const
  {
    return this->castee_effect_value_percent_2_.get ();
  }

  inline
  skill_effect_t::castee_effect_value_percent_2_type& skill_effect_t::
  castee_effect_value_percent_2 ()
  {
    return this->castee_effect_value_percent_2_.get ();
  }

  inline
  void skill_effect_t::
  castee_effect_value_percent_2 (const castee_effect_value_percent_2_type& x)
  {
    this->castee_effect_value_percent_2_.set (x);
  }

  inline
  const skill_effect_t::castee_usable_status_type_2_type& skill_effect_t::
  castee_usable_status_type_2 () const
  {
    return this->castee_usable_status_type_2_.get ();
  }

  inline
  skill_effect_t::castee_usable_status_type_2_type& skill_effect_t::
  castee_usable_status_type_2 ()
  {
    return this->castee_usable_status_type_2_.get ();
  }

  inline
  void skill_effect_t::
  castee_usable_status_type_2 (const castee_usable_status_type_2_type& x)
  {
    this->castee_usable_status_type_2_.set (x);
  }

  inline
  void skill_effect_t::
  castee_usable_status_type_2 (::std::unique_ptr< castee_usable_status_type_2_type > x)
  {
    this->castee_usable_status_type_2_.set (std::move (x));
  }


  // effect_status_type_t
  // 


  // use_target_status_type_t
  // 


  // skill_effect_table
  // 

  inline
  const skill_effect_table::skill_effect_template_sequence& skill_effect_table::
  skill_effect_template () const
  {
    return this->skill_effect_template_;
  }

  inline
  skill_effect_table::skill_effect_template_sequence& skill_effect_table::
  skill_effect_template ()
  {
    return this->skill_effect_template_;
  }

  inline
  void skill_effect_table::
  skill_effect_template (const skill_effect_template_sequence& s)
  {
    this->skill_effect_template_ = s;
  }
}

// Begin epilogue.
//
//
// End epilogue.

#endif // GDT_SKILL_EFFECT_TABLE_IXX
