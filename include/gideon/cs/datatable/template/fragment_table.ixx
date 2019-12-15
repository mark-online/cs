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

#ifndef GDT_FRAGMENT_TABLE_IXX
#define GDT_FRAGMENT_TABLE_IXX

// Begin prologue.
//
//
// End prologue.

#include "shared_types.ixx"

namespace gdt
{
  // fragment_t
  // 

  inline
  const fragment_t::item_code_type& fragment_t::
  item_code () const
  {
    return this->item_code_.get ();
  }

  inline
  fragment_t::item_code_type& fragment_t::
  item_code ()
  {
    return this->item_code_.get ();
  }

  inline
  void fragment_t::
  item_code (const item_code_type& x)
  {
    this->item_code_.set (x);
  }

  inline
  void fragment_t::
  item_code (::std::unique_ptr< item_code_type > x)
  {
    this->item_code_.set (std::move (x));
  }

  inline
  const fragment_t::looting_mil_sec_type& fragment_t::
  looting_mil_sec () const
  {
    return this->looting_mil_sec_.get ();
  }

  inline
  fragment_t::looting_mil_sec_type& fragment_t::
  looting_mil_sec ()
  {
    return this->looting_mil_sec_.get ();
  }

  inline
  void fragment_t::
  looting_mil_sec (const looting_mil_sec_type& x)
  {
    this->looting_mil_sec_.set (x);
  }

  inline
  const fragment_t::stack_count_type& fragment_t::
  stack_count () const
  {
    return this->stack_count_.get ();
  }

  inline
  fragment_t::stack_count_type& fragment_t::
  stack_count ()
  {
    return this->stack_count_.get ();
  }

  inline
  void fragment_t::
  stack_count (const stack_count_type& x)
  {
    this->stack_count_.set (x);
  }

  inline
  const fragment_t::sell_cost_type_type& fragment_t::
  sell_cost_type () const
  {
    return this->sell_cost_type_.get ();
  }

  inline
  fragment_t::sell_cost_type_type& fragment_t::
  sell_cost_type ()
  {
    return this->sell_cost_type_.get ();
  }

  inline
  void fragment_t::
  sell_cost_type (const sell_cost_type_type& x)
  {
    this->sell_cost_type_.set (x);
  }

  inline
  void fragment_t::
  sell_cost_type (::std::unique_ptr< sell_cost_type_type > x)
  {
    this->sell_cost_type_.set (std::move (x));
  }

  inline
  const fragment_t::sell_cost_type1& fragment_t::
  sell_cost () const
  {
    return this->sell_cost_.get ();
  }

  inline
  fragment_t::sell_cost_type1& fragment_t::
  sell_cost ()
  {
    return this->sell_cost_.get ();
  }

  inline
  void fragment_t::
  sell_cost (const sell_cost_type1& x)
  {
    this->sell_cost_.set (x);
  }

  inline
  const fragment_t::buy_cost_type_1_type& fragment_t::
  buy_cost_type_1 () const
  {
    return this->buy_cost_type_1_.get ();
  }

  inline
  fragment_t::buy_cost_type_1_type& fragment_t::
  buy_cost_type_1 ()
  {
    return this->buy_cost_type_1_.get ();
  }

  inline
  void fragment_t::
  buy_cost_type_1 (const buy_cost_type_1_type& x)
  {
    this->buy_cost_type_1_.set (x);
  }

  inline
  void fragment_t::
  buy_cost_type_1 (::std::unique_ptr< buy_cost_type_1_type > x)
  {
    this->buy_cost_type_1_.set (std::move (x));
  }

  inline
  const fragment_t::buy_cost_1_type& fragment_t::
  buy_cost_1 () const
  {
    return this->buy_cost_1_.get ();
  }

  inline
  fragment_t::buy_cost_1_type& fragment_t::
  buy_cost_1 ()
  {
    return this->buy_cost_1_.get ();
  }

  inline
  void fragment_t::
  buy_cost_1 (const buy_cost_1_type& x)
  {
    this->buy_cost_1_.set (x);
  }

  inline
  const fragment_t::buy_cost_type_2_type& fragment_t::
  buy_cost_type_2 () const
  {
    return this->buy_cost_type_2_.get ();
  }

  inline
  fragment_t::buy_cost_type_2_type& fragment_t::
  buy_cost_type_2 ()
  {
    return this->buy_cost_type_2_.get ();
  }

  inline
  void fragment_t::
  buy_cost_type_2 (const buy_cost_type_2_type& x)
  {
    this->buy_cost_type_2_.set (x);
  }

  inline
  void fragment_t::
  buy_cost_type_2 (::std::unique_ptr< buy_cost_type_2_type > x)
  {
    this->buy_cost_type_2_.set (std::move (x));
  }

  inline
  const fragment_t::buy_cost_2_type& fragment_t::
  buy_cost_2 () const
  {
    return this->buy_cost_2_.get ();
  }

  inline
  fragment_t::buy_cost_2_type& fragment_t::
  buy_cost_2 ()
  {
    return this->buy_cost_2_.get ();
  }

  inline
  void fragment_t::
  buy_cost_2 (const buy_cost_2_type& x)
  {
    this->buy_cost_2_.set (x);
  }

  inline
  const fragment_t::icon_name_type& fragment_t::
  icon_name () const
  {
    return this->icon_name_.get ();
  }

  inline
  fragment_t::icon_name_type& fragment_t::
  icon_name ()
  {
    return this->icon_name_.get ();
  }

  inline
  void fragment_t::
  icon_name (const icon_name_type& x)
  {
    this->icon_name_.set (x);
  }

  inline
  void fragment_t::
  icon_name (::std::unique_ptr< icon_name_type > x)
  {
    this->icon_name_.set (std::move (x));
  }


  // fragment_table
  // 

  inline
  const fragment_table::fragment_template_sequence& fragment_table::
  fragment_template () const
  {
    return this->fragment_template_;
  }

  inline
  fragment_table::fragment_template_sequence& fragment_table::
  fragment_template ()
  {
    return this->fragment_template_;
  }

  inline
  void fragment_table::
  fragment_template (const fragment_template_sequence& s)
  {
    this->fragment_template_ = s;
  }
}

// Begin epilogue.
//
//
// End epilogue.

#endif // GDT_FRAGMENT_TABLE_IXX
