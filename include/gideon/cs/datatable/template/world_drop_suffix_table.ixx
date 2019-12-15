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

#ifndef GDT_WORLD_DROP_SUFFIX_TABLE_IXX
#define GDT_WORLD_DROP_SUFFIX_TABLE_IXX

// Begin prologue.
//
//
// End prologue.

#include "shared_types.ixx"

namespace gdt
{
  // world_drop_suffix_t
  // 

  inline
  const world_drop_suffix_t::index_type& world_drop_suffix_t::
  index () const
  {
    return this->index_.get ();
  }

  inline
  world_drop_suffix_t::index_type& world_drop_suffix_t::
  index ()
  {
    return this->index_.get ();
  }

  inline
  void world_drop_suffix_t::
  index (const index_type& x)
  {
    this->index_.set (x);
  }

  inline
  const world_drop_suffix_t::world_drop_id_1_type& world_drop_suffix_t::
  world_drop_id_1 () const
  {
    return this->world_drop_id_1_.get ();
  }

  inline
  world_drop_suffix_t::world_drop_id_1_type& world_drop_suffix_t::
  world_drop_id_1 ()
  {
    return this->world_drop_id_1_.get ();
  }

  inline
  void world_drop_suffix_t::
  world_drop_id_1 (const world_drop_id_1_type& x)
  {
    this->world_drop_id_1_.set (x);
  }

  inline
  const world_drop_suffix_t::world_drop_id_2_type& world_drop_suffix_t::
  world_drop_id_2 () const
  {
    return this->world_drop_id_2_.get ();
  }

  inline
  world_drop_suffix_t::world_drop_id_2_type& world_drop_suffix_t::
  world_drop_id_2 ()
  {
    return this->world_drop_id_2_.get ();
  }

  inline
  void world_drop_suffix_t::
  world_drop_id_2 (const world_drop_id_2_type& x)
  {
    this->world_drop_id_2_.set (x);
  }

  inline
  const world_drop_suffix_t::world_drop_id_3_type& world_drop_suffix_t::
  world_drop_id_3 () const
  {
    return this->world_drop_id_3_.get ();
  }

  inline
  world_drop_suffix_t::world_drop_id_3_type& world_drop_suffix_t::
  world_drop_id_3 ()
  {
    return this->world_drop_id_3_.get ();
  }

  inline
  void world_drop_suffix_t::
  world_drop_id_3 (const world_drop_id_3_type& x)
  {
    this->world_drop_id_3_.set (x);
  }

  inline
  const world_drop_suffix_t::world_drop_id_4_type& world_drop_suffix_t::
  world_drop_id_4 () const
  {
    return this->world_drop_id_4_.get ();
  }

  inline
  world_drop_suffix_t::world_drop_id_4_type& world_drop_suffix_t::
  world_drop_id_4 ()
  {
    return this->world_drop_id_4_.get ();
  }

  inline
  void world_drop_suffix_t::
  world_drop_id_4 (const world_drop_id_4_type& x)
  {
    this->world_drop_id_4_.set (x);
  }

  inline
  const world_drop_suffix_t::world_drop_id_5_type& world_drop_suffix_t::
  world_drop_id_5 () const
  {
    return this->world_drop_id_5_.get ();
  }

  inline
  world_drop_suffix_t::world_drop_id_5_type& world_drop_suffix_t::
  world_drop_id_5 ()
  {
    return this->world_drop_id_5_.get ();
  }

  inline
  void world_drop_suffix_t::
  world_drop_id_5 (const world_drop_id_5_type& x)
  {
    this->world_drop_id_5_.set (x);
  }

  inline
  const world_drop_suffix_t::loop_count_type& world_drop_suffix_t::
  loop_count () const
  {
    return this->loop_count_.get ();
  }

  inline
  world_drop_suffix_t::loop_count_type& world_drop_suffix_t::
  loop_count ()
  {
    return this->loop_count_.get ();
  }

  inline
  void world_drop_suffix_t::
  loop_count (const loop_count_type& x)
  {
    this->loop_count_.set (x);
  }

  inline
  const world_drop_suffix_t::drop_pct_type& world_drop_suffix_t::
  drop_pct () const
  {
    return this->drop_pct_.get ();
  }

  inline
  world_drop_suffix_t::drop_pct_type& world_drop_suffix_t::
  drop_pct ()
  {
    return this->drop_pct_.get ();
  }

  inline
  void world_drop_suffix_t::
  drop_pct (const drop_pct_type& x)
  {
    this->drop_pct_.set (x);
  }

  inline
  void world_drop_suffix_t::
  drop_pct (::std::unique_ptr< drop_pct_type > x)
  {
    this->drop_pct_.set (std::move (x));
  }


  // world_drop_suffix_table
  // 

  inline
  const world_drop_suffix_table::world_drop_suffix_template_sequence& world_drop_suffix_table::
  world_drop_suffix_template () const
  {
    return this->world_drop_suffix_template_;
  }

  inline
  world_drop_suffix_table::world_drop_suffix_template_sequence& world_drop_suffix_table::
  world_drop_suffix_template ()
  {
    return this->world_drop_suffix_template_;
  }

  inline
  void world_drop_suffix_table::
  world_drop_suffix_template (const world_drop_suffix_template_sequence& s)
  {
    this->world_drop_suffix_template_ = s;
  }
}

// Begin epilogue.
//
//
// End epilogue.

#endif // GDT_WORLD_DROP_SUFFIX_TABLE_IXX
