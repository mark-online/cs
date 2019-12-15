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

#ifndef GDT_BUILDING_GUARD_TABLE_IXX
#define GDT_BUILDING_GUARD_TABLE_IXX

// Begin prologue.
//
//
// End prologue.

#include "shared_types.ixx"

namespace gdt
{
  // building_guard_t
  // 

  inline
  const building_guard_t::building_guard_code_type& building_guard_t::
  building_guard_code () const
  {
    return this->building_guard_code_.get ();
  }

  inline
  building_guard_t::building_guard_code_type& building_guard_t::
  building_guard_code ()
  {
    return this->building_guard_code_.get ();
  }

  inline
  void building_guard_t::
  building_guard_code (const building_guard_code_type& x)
  {
    this->building_guard_code_.set (x);
  }

  inline
  void building_guard_t::
  building_guard_code (::std::unique_ptr< building_guard_code_type > x)
  {
    this->building_guard_code_.set (std::move (x));
  }

  inline
  const building_guard_t::building_guard_icon_type& building_guard_t::
  building_guard_icon () const
  {
    return this->building_guard_icon_.get ();
  }

  inline
  building_guard_t::building_guard_icon_type& building_guard_t::
  building_guard_icon ()
  {
    return this->building_guard_icon_.get ();
  }

  inline
  void building_guard_t::
  building_guard_icon (const building_guard_icon_type& x)
  {
    this->building_guard_icon_.set (x);
  }

  inline
  void building_guard_t::
  building_guard_icon (::std::unique_ptr< building_guard_icon_type > x)
  {
    this->building_guard_icon_.set (std::move (x));
  }

  inline
  const building_guard_t::npc_code_type& building_guard_t::
  npc_code () const
  {
    return this->npc_code_.get ();
  }

  inline
  building_guard_t::npc_code_type& building_guard_t::
  npc_code ()
  {
    return this->npc_code_.get ();
  }

  inline
  void building_guard_t::
  npc_code (const npc_code_type& x)
  {
    this->npc_code_.set (x);
  }

  inline
  void building_guard_t::
  npc_code (::std::unique_ptr< npc_code_type > x)
  {
    this->npc_code_.set (std::move (x));
  }

  inline
  const building_guard_t::day_cost_type& building_guard_t::
  day_cost () const
  {
    return this->day_cost_.get ();
  }

  inline
  building_guard_t::day_cost_type& building_guard_t::
  day_cost ()
  {
    return this->day_cost_.get ();
  }

  inline
  void building_guard_t::
  day_cost (const day_cost_type& x)
  {
    this->day_cost_.set (x);
  }

  inline
  const building_guard_t::check_building_code_type& building_guard_t::
  check_building_code () const
  {
    return this->check_building_code_.get ();
  }

  inline
  building_guard_t::check_building_code_type& building_guard_t::
  check_building_code ()
  {
    return this->check_building_code_.get ();
  }

  inline
  void building_guard_t::
  check_building_code (const check_building_code_type& x)
  {
    this->check_building_code_.set (x);
  }

  inline
  void building_guard_t::
  check_building_code (::std::unique_ptr< check_building_code_type > x)
  {
    this->check_building_code_.set (std::move (x));
  }

  inline
  const building_guard_t::check_building_distance_type& building_guard_t::
  check_building_distance () const
  {
    return this->check_building_distance_.get ();
  }

  inline
  building_guard_t::check_building_distance_type& building_guard_t::
  check_building_distance ()
  {
    return this->check_building_distance_.get ();
  }

  inline
  void building_guard_t::
  check_building_distance (const check_building_distance_type& x)
  {
    this->check_building_distance_.set (x);
  }


  // building_guard_table
  // 

  inline
  const building_guard_table::building_guard_template_sequence& building_guard_table::
  building_guard_template () const
  {
    return this->building_guard_template_;
  }

  inline
  building_guard_table::building_guard_template_sequence& building_guard_table::
  building_guard_template ()
  {
    return this->building_guard_template_;
  }

  inline
  void building_guard_table::
  building_guard_template (const building_guard_template_sequence& s)
  {
    this->building_guard_template_ = s;
  }
}

// Begin epilogue.
//
//
// End epilogue.

#endif // GDT_BUILDING_GUARD_TABLE_IXX