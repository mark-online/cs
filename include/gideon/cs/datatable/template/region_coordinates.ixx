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

#ifndef GDT_REGION_COORDINATES_IXX
#define GDT_REGION_COORDINATES_IXX

// Begin prologue.
//
//
// End prologue.

#include "shared_types.ixx"

namespace gdt
{
  // coordinates_t
  // 

  inline
  const coordinates_t::region_code_type& coordinates_t::
  region_code () const
  {
    return this->region_code_.get ();
  }

  inline
  coordinates_t::region_code_type& coordinates_t::
  region_code ()
  {
    return this->region_code_.get ();
  }

  inline
  void coordinates_t::
  region_code (const region_code_type& x)
  {
    this->region_code_.set (x);
  }

  inline
  void coordinates_t::
  region_code (::std::unique_ptr< region_code_type > x)
  {
    this->region_code_.set (std::move (x));
  }

  inline
  const coordinates_t::radius_type& coordinates_t::
  radius () const
  {
    return this->radius_.get ();
  }

  inline
  coordinates_t::radius_type& coordinates_t::
  radius ()
  {
    return this->radius_.get ();
  }

  inline
  void coordinates_t::
  radius (const radius_type& x)
  {
    this->radius_.set (x);
  }

  inline
  const coordinates_t::x_type& coordinates_t::
  x () const
  {
    return this->x_.get ();
  }

  inline
  coordinates_t::x_type& coordinates_t::
  x ()
  {
    return this->x_.get ();
  }

  inline
  void coordinates_t::
  x (const x_type& x)
  {
    this->x_.set (x);
  }

  inline
  const coordinates_t::y_type& coordinates_t::
  y () const
  {
    return this->y_.get ();
  }

  inline
  coordinates_t::y_type& coordinates_t::
  y ()
  {
    return this->y_.get ();
  }

  inline
  void coordinates_t::
  y (const y_type& x)
  {
    this->y_.set (x);
  }

  inline
  const coordinates_t::z_type& coordinates_t::
  z () const
  {
    return this->z_.get ();
  }

  inline
  coordinates_t::z_type& coordinates_t::
  z ()
  {
    return this->z_.get ();
  }

  inline
  void coordinates_t::
  z (const z_type& x)
  {
    this->z_.set (x);
  }

  inline
  const coordinates_t::x1_type& coordinates_t::
  x1 () const
  {
    return this->x1_.get ();
  }

  inline
  coordinates_t::x1_type& coordinates_t::
  x1 ()
  {
    return this->x1_.get ();
  }

  inline
  void coordinates_t::
  x1 (const x1_type& x)
  {
    this->x1_.set (x);
  }

  inline
  const coordinates_t::x2_type& coordinates_t::
  x2 () const
  {
    return this->x2_.get ();
  }

  inline
  coordinates_t::x2_type& coordinates_t::
  x2 ()
  {
    return this->x2_.get ();
  }

  inline
  void coordinates_t::
  x2 (const x2_type& x)
  {
    this->x2_.set (x);
  }

  inline
  const coordinates_t::y1_type& coordinates_t::
  y1 () const
  {
    return this->y1_.get ();
  }

  inline
  coordinates_t::y1_type& coordinates_t::
  y1 ()
  {
    return this->y1_.get ();
  }

  inline
  void coordinates_t::
  y1 (const y1_type& x)
  {
    this->y1_.set (x);
  }

  inline
  const coordinates_t::y2_type& coordinates_t::
  y2 () const
  {
    return this->y2_.get ();
  }

  inline
  coordinates_t::y2_type& coordinates_t::
  y2 ()
  {
    return this->y2_.get ();
  }

  inline
  void coordinates_t::
  y2 (const y2_type& x)
  {
    this->y2_.set (x);
  }


  // region_coordinates
  // 

  inline
  const region_coordinates::coordinates_sequence& region_coordinates::
  coordinates () const
  {
    return this->coordinates_;
  }

  inline
  region_coordinates::coordinates_sequence& region_coordinates::
  coordinates ()
  {
    return this->coordinates_;
  }

  inline
  void region_coordinates::
  coordinates (const coordinates_sequence& s)
  {
    this->coordinates_ = s;
  }
}

// Begin epilogue.
//
//
// End epilogue.

#endif // GDT_REGION_COORDINATES_IXX
