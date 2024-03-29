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

#ifndef GDT_DEVICE_TABLE_IXX
#define GDT_DEVICE_TABLE_IXX

// Begin prologue.
//
//
// End prologue.

#include "shared_types.ixx"

namespace gdt
{
  // device_t
  // 

  inline
  const device_t::device_code_type& device_t::
  device_code () const
  {
    return this->device_code_.get ();
  }

  inline
  device_t::device_code_type& device_t::
  device_code ()
  {
    return this->device_code_.get ();
  }

  inline
  void device_t::
  device_code (const device_code_type& x)
  {
    this->device_code_.set (x);
  }

  inline
  void device_t::
  device_code (::std::unique_ptr< device_code_type > x)
  {
    this->device_code_.set (std::move (x));
  }

  inline
  const device_t::modeling_type& device_t::
  modeling () const
  {
    return this->modeling_.get ();
  }

  inline
  device_t::modeling_type& device_t::
  modeling ()
  {
    return this->modeling_.get ();
  }

  inline
  void device_t::
  modeling (const modeling_type& x)
  {
    this->modeling_.set (x);
  }

  inline
  void device_t::
  modeling (::std::unique_ptr< modeling_type > x)
  {
    this->modeling_.set (std::move (x));
  }

  inline
  const device_t::reactivate_interval_type& device_t::
  reactivate_interval () const
  {
    return this->reactivate_interval_.get ();
  }

  inline
  device_t::reactivate_interval_type& device_t::
  reactivate_interval ()
  {
    return this->reactivate_interval_.get ();
  }

  inline
  void device_t::
  reactivate_interval (const reactivate_interval_type& x)
  {
    this->reactivate_interval_.set (x);
  }

  inline
  const device_t::activate_animation_type& device_t::
  activate_animation () const
  {
    return this->activate_animation_.get ();
  }

  inline
  device_t::activate_animation_type& device_t::
  activate_animation ()
  {
    return this->activate_animation_.get ();
  }

  inline
  void device_t::
  activate_animation (const activate_animation_type& x)
  {
    this->activate_animation_.set (x);
  }

  inline
  void device_t::
  activate_animation (::std::unique_ptr< activate_animation_type > x)
  {
    this->activate_animation_.set (std::move (x));
  }

  inline
  const device_t::object_ambient_anim_type& device_t::
  object_ambient_anim () const
  {
    return this->object_ambient_anim_.get ();
  }

  inline
  device_t::object_ambient_anim_type& device_t::
  object_ambient_anim ()
  {
    return this->object_ambient_anim_.get ();
  }

  inline
  void device_t::
  object_ambient_anim (const object_ambient_anim_type& x)
  {
    this->object_ambient_anim_.set (x);
  }

  inline
  void device_t::
  object_ambient_anim (::std::unique_ptr< object_ambient_anim_type > x)
  {
    this->object_ambient_anim_.set (std::move (x));
  }

  inline
  const device_t::cast_time_type& device_t::
  cast_time () const
  {
    return this->cast_time_.get ();
  }

  inline
  device_t::cast_time_type& device_t::
  cast_time ()
  {
    return this->cast_time_.get ();
  }

  inline
  void device_t::
  cast_time (const cast_time_type& x)
  {
    this->cast_time_.set (x);
  }

  inline
  const device_t::condition1_type_type& device_t::
  condition1_type () const
  {
    return this->condition1_type_.get ();
  }

  inline
  device_t::condition1_type_type& device_t::
  condition1_type ()
  {
    return this->condition1_type_.get ();
  }

  inline
  void device_t::
  condition1_type (const condition1_type_type& x)
  {
    this->condition1_type_.set (x);
  }

  inline
  void device_t::
  condition1_type (::std::unique_ptr< condition1_type_type > x)
  {
    this->condition1_type_.set (std::move (x));
  }

  inline
  const device_t::condition1_param1_type& device_t::
  condition1_param1 () const
  {
    return this->condition1_param1_.get ();
  }

  inline
  device_t::condition1_param1_type& device_t::
  condition1_param1 ()
  {
    return this->condition1_param1_.get ();
  }

  inline
  void device_t::
  condition1_param1 (const condition1_param1_type& x)
  {
    this->condition1_param1_.set (x);
  }

  inline
  const device_t::condition1_param2_type& device_t::
  condition1_param2 () const
  {
    return this->condition1_param2_.get ();
  }

  inline
  device_t::condition1_param2_type& device_t::
  condition1_param2 ()
  {
    return this->condition1_param2_.get ();
  }

  inline
  void device_t::
  condition1_param2 (const condition1_param2_type& x)
  {
    this->condition1_param2_.set (x);
  }

  inline
  const device_t::condition2_type_type& device_t::
  condition2_type () const
  {
    return this->condition2_type_.get ();
  }

  inline
  device_t::condition2_type_type& device_t::
  condition2_type ()
  {
    return this->condition2_type_.get ();
  }

  inline
  void device_t::
  condition2_type (const condition2_type_type& x)
  {
    this->condition2_type_.set (x);
  }

  inline
  void device_t::
  condition2_type (::std::unique_ptr< condition2_type_type > x)
  {
    this->condition2_type_.set (std::move (x));
  }

  inline
  const device_t::condition2_param1_type& device_t::
  condition2_param1 () const
  {
    return this->condition2_param1_.get ();
  }

  inline
  device_t::condition2_param1_type& device_t::
  condition2_param1 ()
  {
    return this->condition2_param1_.get ();
  }

  inline
  void device_t::
  condition2_param1 (const condition2_param1_type& x)
  {
    this->condition2_param1_.set (x);
  }

  inline
  const device_t::condition2_param2_type& device_t::
  condition2_param2 () const
  {
    return this->condition2_param2_.get ();
  }

  inline
  device_t::condition2_param2_type& device_t::
  condition2_param2 ()
  {
    return this->condition2_param2_.get ();
  }

  inline
  void device_t::
  condition2_param2 (const condition2_param2_type& x)
  {
    this->condition2_param2_.set (x);
  }

  inline
  const device_t::object_effect_type& device_t::
  object_effect () const
  {
    return this->object_effect_.get ();
  }

  inline
  device_t::object_effect_type& device_t::
  object_effect ()
  {
    return this->object_effect_.get ();
  }

  inline
  void device_t::
  object_effect (const object_effect_type& x)
  {
    this->object_effect_.set (x);
  }

  inline
  void device_t::
  object_effect (::std::unique_ptr< object_effect_type > x)
  {
    this->object_effect_.set (std::move (x));
  }

  inline
  const device_t::object_activated_anim_type& device_t::
  object_activated_anim () const
  {
    return this->object_activated_anim_.get ();
  }

  inline
  device_t::object_activated_anim_type& device_t::
  object_activated_anim ()
  {
    return this->object_activated_anim_.get ();
  }

  inline
  void device_t::
  object_activated_anim (const object_activated_anim_type& x)
  {
    this->object_activated_anim_.set (x);
  }

  inline
  void device_t::
  object_activated_anim (::std::unique_ptr< object_activated_anim_type > x)
  {
    this->object_activated_anim_.set (std::move (x));
  }

  inline
  const device_t::object_activated_effect_type& device_t::
  object_activated_effect () const
  {
    return this->object_activated_effect_.get ();
  }

  inline
  device_t::object_activated_effect_type& device_t::
  object_activated_effect ()
  {
    return this->object_activated_effect_.get ();
  }

  inline
  void device_t::
  object_activated_effect (const object_activated_effect_type& x)
  {
    this->object_activated_effect_.set (x);
  }

  inline
  void device_t::
  object_activated_effect (::std::unique_ptr< object_activated_effect_type > x)
  {
    this->object_activated_effect_.set (std::move (x));
  }

  inline
  const device_t::activate_type_type& device_t::
  activate_type () const
  {
    return this->activate_type_.get ();
  }

  inline
  device_t::activate_type_type& device_t::
  activate_type ()
  {
    return this->activate_type_.get ();
  }

  inline
  void device_t::
  activate_type (const activate_type_type& x)
  {
    this->activate_type_.set (x);
  }

  inline
  const device_t::activate_param1_type& device_t::
  activate_param1 () const
  {
    return this->activate_param1_.get ();
  }

  inline
  device_t::activate_param1_type& device_t::
  activate_param1 ()
  {
    return this->activate_param1_.get ();
  }

  inline
  void device_t::
  activate_param1 (const activate_param1_type& x)
  {
    this->activate_param1_.set (x);
  }

  inline
  void device_t::
  activate_param1 (::std::unique_ptr< activate_param1_type > x)
  {
    this->activate_param1_.set (std::move (x));
  }

  inline
  const device_t::activate_param2_type& device_t::
  activate_param2 () const
  {
    return this->activate_param2_.get ();
  }

  inline
  device_t::activate_param2_type& device_t::
  activate_param2 ()
  {
    return this->activate_param2_.get ();
  }

  inline
  void device_t::
  activate_param2 (const activate_param2_type& x)
  {
    this->activate_param2_.set (x);
  }

  inline
  void device_t::
  activate_param2 (::std::unique_ptr< activate_param2_type > x)
  {
    this->activate_param2_.set (std::move (x));
  }

  inline
  const device_t::activate_param3_type& device_t::
  activate_param3 () const
  {
    return this->activate_param3_.get ();
  }

  inline
  device_t::activate_param3_type& device_t::
  activate_param3 ()
  {
    return this->activate_param3_.get ();
  }

  inline
  void device_t::
  activate_param3 (const activate_param3_type& x)
  {
    this->activate_param3_.set (x);
  }

  inline
  void device_t::
  activate_param3 (::std::unique_ptr< activate_param3_type > x)
  {
    this->activate_param3_.set (std::move (x));
  }

  inline
  const device_t::mount_datablock_name_type& device_t::
  mount_datablock_name () const
  {
    return this->mount_datablock_name_.get ();
  }

  inline
  device_t::mount_datablock_name_type& device_t::
  mount_datablock_name ()
  {
    return this->mount_datablock_name_.get ();
  }

  inline
  void device_t::
  mount_datablock_name (const mount_datablock_name_type& x)
  {
    this->mount_datablock_name_.set (x);
  }

  inline
  void device_t::
  mount_datablock_name (::std::unique_ptr< mount_datablock_name_type > x)
  {
    this->mount_datablock_name_.set (std::move (x));
  }

  inline
  const device_t::start_dealy_time_min_type& device_t::
  start_dealy_time_min () const
  {
    return this->start_dealy_time_min_.get ();
  }

  inline
  device_t::start_dealy_time_min_type& device_t::
  start_dealy_time_min ()
  {
    return this->start_dealy_time_min_.get ();
  }

  inline
  void device_t::
  start_dealy_time_min (const start_dealy_time_min_type& x)
  {
    this->start_dealy_time_min_.set (x);
  }

  inline
  const device_t::start_dealy_time_max_type& device_t::
  start_dealy_time_max () const
  {
    return this->start_dealy_time_max_.get ();
  }

  inline
  device_t::start_dealy_time_max_type& device_t::
  start_dealy_time_max ()
  {
    return this->start_dealy_time_max_.get ();
  }

  inline
  void device_t::
  start_dealy_time_max (const start_dealy_time_max_type& x)
  {
    this->start_dealy_time_max_.set (x);
  }


  // condition_type_t
  // 


  // device_table
  // 

  inline
  const device_table::device_template_sequence& device_table::
  device_template () const
  {
    return this->device_template_;
  }

  inline
  device_table::device_template_sequence& device_table::
  device_template ()
  {
    return this->device_template_;
  }

  inline
  void device_table::
  device_template (const device_template_sequence& s)
  {
    this->device_template_ = s;
  }
}

// Begin epilogue.
//
//
// End epilogue.

#endif // GDT_DEVICE_TABLE_IXX
