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

#ifndef GDT_GUILD_LEVEL_TABLE_IXX
#define GDT_GUILD_LEVEL_TABLE_IXX

// Begin prologue.
//
//
// End prologue.

#include "shared_types.ixx"

namespace gdt
{
  // guild_level_t
  // 

  inline
  const guild_level_t::guild_level_type& guild_level_t::
  guild_level () const
  {
    return this->guild_level_.get ();
  }

  inline
  guild_level_t::guild_level_type& guild_level_t::
  guild_level ()
  {
    return this->guild_level_.get ();
  }

  inline
  void guild_level_t::
  guild_level (const guild_level_type& x)
  {
    this->guild_level_.set (x);
  }

  inline
  const guild_level_t::exp_type& guild_level_t::
  exp () const
  {
    return this->exp_.get ();
  }

  inline
  guild_level_t::exp_type& guild_level_t::
  exp ()
  {
    return this->exp_.get ();
  }

  inline
  void guild_level_t::
  exp (const exp_type& x)
  {
    this->exp_.set (x);
  }

  inline
  const guild_level_t::guild_member_count_type& guild_level_t::
  guild_member_count () const
  {
    return this->guild_member_count_.get ();
  }

  inline
  guild_level_t::guild_member_count_type& guild_level_t::
  guild_member_count ()
  {
    return this->guild_member_count_.get ();
  }

  inline
  void guild_level_t::
  guild_member_count (const guild_member_count_type& x)
  {
    this->guild_member_count_.set (x);
  }


  // guild_level_table
  // 

  inline
  const guild_level_table::guild_level_template_sequence& guild_level_table::
  guild_level_template () const
  {
    return this->guild_level_template_;
  }

  inline
  guild_level_table::guild_level_template_sequence& guild_level_table::
  guild_level_template ()
  {
    return this->guild_level_template_;
  }

  inline
  void guild_level_table::
  guild_level_template (const guild_level_template_sequence& s)
  {
    this->guild_level_template_ = s;
  }
}

// Begin epilogue.
//
//
// End epilogue.

#endif // GDT_GUILD_LEVEL_TABLE_IXX
