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

#ifndef GDT_ACTION_TABLE_IXX
#define GDT_ACTION_TABLE_IXX

// Begin prologue.
//
//
// End prologue.

#include "shared_types.ixx"

namespace gdt
{
  // action_t
  // 

  inline
  const action_t::action_code_type& action_t::
  action_code () const
  {
    return this->action_code_.get ();
  }

  inline
  action_t::action_code_type& action_t::
  action_code ()
  {
    return this->action_code_.get ();
  }

  inline
  void action_t::
  action_code (const action_code_type& x)
  {
    this->action_code_.set (x);
  }

  inline
  const action_t::anim_name_type& action_t::
  anim_name () const
  {
    return this->anim_name_.get ();
  }

  inline
  action_t::anim_name_type& action_t::
  anim_name ()
  {
    return this->anim_name_.get ();
  }

  inline
  void action_t::
  anim_name (const anim_name_type& x)
  {
    this->anim_name_.set (x);
  }

  inline
  void action_t::
  anim_name (::std::unique_ptr< anim_name_type > x)
  {
    this->anim_name_.set (std::move (x));
  }

  inline
  const action_t::effect_name_type& action_t::
  effect_name () const
  {
    return this->effect_name_.get ();
  }

  inline
  action_t::effect_name_type& action_t::
  effect_name ()
  {
    return this->effect_name_.get ();
  }

  inline
  void action_t::
  effect_name (const effect_name_type& x)
  {
    this->effect_name_.set (x);
  }

  inline
  void action_t::
  effect_name (::std::unique_ptr< effect_name_type > x)
  {
    this->effect_name_.set (std::move (x));
  }

  inline
  const action_t::action_is_moving_type& action_t::
  action_is_moving () const
  {
    return this->action_is_moving_.get ();
  }

  inline
  action_t::action_is_moving_type& action_t::
  action_is_moving ()
  {
    return this->action_is_moving_.get ();
  }

  inline
  void action_t::
  action_is_moving (const action_is_moving_type& x)
  {
    this->action_is_moving_.set (x);
  }

  inline
  const action_t::play_time_type& action_t::
  play_time () const
  {
    return this->play_time_.get ();
  }

  inline
  action_t::play_time_type& action_t::
  play_time ()
  {
    return this->play_time_.get ();
  }

  inline
  void action_t::
  play_time (const play_time_type& x)
  {
    this->play_time_.set (x);
  }


  // action_table
  // 

  inline
  const action_table::action_template_sequence& action_table::
  action_template () const
  {
    return this->action_template_;
  }

  inline
  action_table::action_template_sequence& action_table::
  action_template ()
  {
    return this->action_template_;
  }

  inline
  void action_table::
  action_template (const action_template_sequence& s)
  {
    this->action_template_ = s;
  }
}

// Begin epilogue.
//
//
// End epilogue.

#endif // GDT_ACTION_TABLE_IXX