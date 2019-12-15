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

#ifndef GDT_WORLD_EVENT_MISSION_SPAWN_TABLE_IXX
#define GDT_WORLD_EVENT_MISSION_SPAWN_TABLE_IXX

// Begin prologue.
//
//
// End prologue.

#include "shared_types.ixx"

namespace gdt
{
  // world_event_mission_spawn_t
  // 

  inline
  const world_event_mission_spawn_t::mission_code_type& world_event_mission_spawn_t::
  mission_code () const
  {
    return this->mission_code_.get ();
  }

  inline
  world_event_mission_spawn_t::mission_code_type& world_event_mission_spawn_t::
  mission_code ()
  {
    return this->mission_code_.get ();
  }

  inline
  void world_event_mission_spawn_t::
  mission_code (const mission_code_type& x)
  {
    this->mission_code_.set (x);
  }

  inline
  void world_event_mission_spawn_t::
  mission_code (::std::unique_ptr< mission_code_type > x)
  {
    this->mission_code_.set (std::move (x));
  }

  inline
  const world_event_mission_spawn_t::entity_code_type& world_event_mission_spawn_t::
  entity_code () const
  {
    return this->entity_code_.get ();
  }

  inline
  world_event_mission_spawn_t::entity_code_type& world_event_mission_spawn_t::
  entity_code ()
  {
    return this->entity_code_.get ();
  }

  inline
  void world_event_mission_spawn_t::
  entity_code (const entity_code_type& x)
  {
    this->entity_code_.set (x);
  }

  inline
  const world_event_mission_spawn_t::entity_path_code_type& world_event_mission_spawn_t::
  entity_path_code () const
  {
    return this->entity_path_code_.get ();
  }

  inline
  world_event_mission_spawn_t::entity_path_code_type& world_event_mission_spawn_t::
  entity_path_code ()
  {
    return this->entity_path_code_.get ();
  }

  inline
  void world_event_mission_spawn_t::
  entity_path_code (const entity_path_code_type& x)
  {
    this->entity_path_code_.set (x);
  }

  inline
  const world_event_mission_spawn_t::pool_type& world_event_mission_spawn_t::
  pool () const
  {
    return this->pool_.get ();
  }

  inline
  world_event_mission_spawn_t::pool_type& world_event_mission_spawn_t::
  pool ()
  {
    return this->pool_.get ();
  }

  inline
  void world_event_mission_spawn_t::
  pool (const pool_type& x)
  {
    this->pool_.set (x);
  }

  inline
  const world_event_mission_spawn_t::mission_phase_type& world_event_mission_spawn_t::
  mission_phase () const
  {
    return this->mission_phase_.get ();
  }

  inline
  world_event_mission_spawn_t::mission_phase_type& world_event_mission_spawn_t::
  mission_phase ()
  {
    return this->mission_phase_.get ();
  }

  inline
  void world_event_mission_spawn_t::
  mission_phase (const mission_phase_type& x)
  {
    this->mission_phase_.set (x);
  }

  inline
  const world_event_mission_spawn_t::should_notify_movement_type& world_event_mission_spawn_t::
  should_notify_movement () const
  {
    return this->should_notify_movement_.get ();
  }

  inline
  world_event_mission_spawn_t::should_notify_movement_type& world_event_mission_spawn_t::
  should_notify_movement ()
  {
    return this->should_notify_movement_.get ();
  }

  inline
  void world_event_mission_spawn_t::
  should_notify_movement (const should_notify_movement_type& x)
  {
    this->should_notify_movement_.set (x);
  }

  inline
  const world_event_mission_spawn_t::join_react_distance_type& world_event_mission_spawn_t::
  join_react_distance () const
  {
    return this->join_react_distance_.get ();
  }

  inline
  world_event_mission_spawn_t::join_react_distance_type& world_event_mission_spawn_t::
  join_react_distance ()
  {
    return this->join_react_distance_.get ();
  }

  inline
  void world_event_mission_spawn_t::
  join_react_distance (const join_react_distance_type& x)
  {
    this->join_react_distance_.set (x);
  }


  // world_event_mission_spawn_table
  // 

  inline
  const world_event_mission_spawn_table::world_event_mission_spawn_template_sequence& world_event_mission_spawn_table::
  world_event_mission_spawn_template () const
  {
    return this->world_event_mission_spawn_template_;
  }

  inline
  world_event_mission_spawn_table::world_event_mission_spawn_template_sequence& world_event_mission_spawn_table::
  world_event_mission_spawn_template ()
  {
    return this->world_event_mission_spawn_template_;
  }

  inline
  void world_event_mission_spawn_table::
  world_event_mission_spawn_template (const world_event_mission_spawn_template_sequence& s)
  {
    this->world_event_mission_spawn_template_ = s;
  }
}

// Begin epilogue.
//
//
// End epilogue.

#endif // GDT_WORLD_EVENT_MISSION_SPAWN_TABLE_IXX
