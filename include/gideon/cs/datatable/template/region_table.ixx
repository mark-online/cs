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

#ifndef GDT_REGION_TABLE_IXX
#define GDT_REGION_TABLE_IXX

// Begin prologue.
//
//
// End prologue.

#include "shared_types.ixx"

namespace gdt
{
  // region_t
  // 

  inline
  const region_t::region_code_type& region_t::
  region_code () const
  {
    return this->region_code_.get ();
  }

  inline
  region_t::region_code_type& region_t::
  region_code ()
  {
    return this->region_code_.get ();
  }

  inline
  void region_t::
  region_code (const region_code_type& x)
  {
    this->region_code_.set (x);
  }

  inline
  void region_t::
  region_code (::std::unique_ptr< region_code_type > x)
  {
    this->region_code_.set (std::move (x));
  }

  inline
  const region_t::param1_type& region_t::
  param1 () const
  {
    return this->param1_.get ();
  }

  inline
  region_t::param1_type& region_t::
  param1 ()
  {
    return this->param1_.get ();
  }

  inline
  void region_t::
  param1 (const param1_type& x)
  {
    this->param1_.set (x);
  }

  inline
  const region_t::param2_type& region_t::
  param2 () const
  {
    return this->param2_.get ();
  }

  inline
  region_t::param2_type& region_t::
  param2 ()
  {
    return this->param2_.get ();
  }

  inline
  void region_t::
  param2 (const param2_type& x)
  {
    this->param2_.set (x);
  }


  // region_table
  // 

  inline
  const region_table::region_template_sequence& region_table::
  region_template () const
  {
    return this->region_template_;
  }

  inline
  region_table::region_template_sequence& region_table::
  region_template ()
  {
    return this->region_template_;
  }

  inline
  void region_table::
  region_template (const region_template_sequence& s)
  {
    this->region_template_ = s;
  }
}

// Begin epilogue.
//
//
// End epilogue.

#endif // GDT_REGION_TABLE_IXX
