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

// Begin prologue.
//
#include <DataTablePCH.h>
//
// End prologue.

#include <xsd/cxx/pre.hxx>

#include "npc_formation_table.hxx"

#include <xsd/cxx/xml/dom/parsing-source.hxx>

namespace gdt
{
  // npc_formation_t
  //

  npc_formation_t::
  npc_formation_t ()
  : ::xml_schema::type (),
    leader_npc_code_ (this),
    member_npc_code_ (this),
    max_distance_ (this),
    angle_ (this),
    react_type_ (this)
  {
  }

  npc_formation_t::
  npc_formation_t (const leader_npc_code_type& leader_npc_code,
                   const member_npc_code_type& member_npc_code,
                   const max_distance_type& max_distance,
                   const angle_type& angle,
                   const react_type_type& react_type)
  : ::xml_schema::type (),
    leader_npc_code_ (leader_npc_code, this),
    member_npc_code_ (member_npc_code, this),
    max_distance_ (max_distance, this),
    angle_ (angle, this),
    react_type_ (react_type, this)
  {
  }

  npc_formation_t::
  npc_formation_t (const npc_formation_t& x,
                   ::xml_schema::flags f,
                   ::xml_schema::container* c)
  : ::xml_schema::type (x, f, c),
    leader_npc_code_ (x.leader_npc_code_, f, this),
    member_npc_code_ (x.member_npc_code_, f, this),
    max_distance_ (x.max_distance_, f, this),
    angle_ (x.angle_, f, this),
    react_type_ (x.react_type_, f, this)
  {
  }

  npc_formation_t::
  npc_formation_t (const ::xercesc::DOMElement& e,
                   ::xml_schema::flags f,
                   ::xml_schema::container* c)
  : ::xml_schema::type (e, f | ::xml_schema::flags::base, c),
    leader_npc_code_ (this),
    member_npc_code_ (this),
    max_distance_ (this),
    angle_ (this),
    react_type_ (this)
  {
    if ((f & ::xml_schema::flags::base) == 0)
    {
      ::xsd::cxx::xml::dom::parser< wchar_t > p (e, false, false, true);
      this->parse (p, f);
    }
  }

  void npc_formation_t::
  parse (::xsd::cxx::xml::dom::parser< wchar_t >& p,
         ::xml_schema::flags f)
  {
    while (p.more_attributes ())
    {
      const ::xercesc::DOMAttr& i (p.next_attribute ());
      const ::xsd::cxx::xml::qualified_name< wchar_t > n (
        ::xsd::cxx::xml::dom::name< wchar_t > (i));

      if (n.name () == L"leader_npc_code" && n.namespace_ ().empty ())
      {
        this->leader_npc_code_.set (leader_npc_code_traits::create (i, f, this));
        continue;
      }

      if (n.name () == L"member_npc_code" && n.namespace_ ().empty ())
      {
        this->member_npc_code_.set (member_npc_code_traits::create (i, f, this));
        continue;
      }

      if (n.name () == L"max_distance" && n.namespace_ ().empty ())
      {
        this->max_distance_.set (max_distance_traits::create (i, f, this));
        continue;
      }

      if (n.name () == L"angle" && n.namespace_ ().empty ())
      {
        this->angle_.set (angle_traits::create (i, f, this));
        continue;
      }

      if (n.name () == L"react_type" && n.namespace_ ().empty ())
      {
        this->react_type_.set (react_type_traits::create (i, f, this));
        continue;
      }
    }

    if (!leader_npc_code_.present ())
    {
      throw ::xsd::cxx::tree::expected_attribute< wchar_t > (
        L"leader_npc_code",
        L"");
    }

    if (!member_npc_code_.present ())
    {
      throw ::xsd::cxx::tree::expected_attribute< wchar_t > (
        L"member_npc_code",
        L"");
    }

    if (!max_distance_.present ())
    {
      throw ::xsd::cxx::tree::expected_attribute< wchar_t > (
        L"max_distance",
        L"");
    }

    if (!angle_.present ())
    {
      throw ::xsd::cxx::tree::expected_attribute< wchar_t > (
        L"angle",
        L"");
    }

    if (!react_type_.present ())
    {
      throw ::xsd::cxx::tree::expected_attribute< wchar_t > (
        L"react_type",
        L"");
    }
  }

  npc_formation_t* npc_formation_t::
  _clone (::xml_schema::flags f,
          ::xml_schema::container* c) const
  {
    return new class npc_formation_t (*this, f, c);
  }

  npc_formation_t& npc_formation_t::
  operator= (const npc_formation_t& x)
  {
    if (this != &x)
    {
      static_cast< ::xml_schema::type& > (*this) = x;
      this->leader_npc_code_ = x.leader_npc_code_;
      this->member_npc_code_ = x.member_npc_code_;
      this->max_distance_ = x.max_distance_;
      this->angle_ = x.angle_;
      this->react_type_ = x.react_type_;
    }

    return *this;
  }

  npc_formation_t::
  ~npc_formation_t ()
  {
  }

  // npc_formation_table
  //

  npc_formation_table::
  npc_formation_table ()
  : ::xml_schema::type (),
    npc_formation_template_ (this)
  {
  }

  npc_formation_table::
  npc_formation_table (const npc_formation_table& x,
                       ::xml_schema::flags f,
                       ::xml_schema::container* c)
  : ::xml_schema::type (x, f, c),
    npc_formation_template_ (x.npc_formation_template_, f, this)
  {
  }

  npc_formation_table::
  npc_formation_table (const ::xercesc::DOMElement& e,
                       ::xml_schema::flags f,
                       ::xml_schema::container* c)
  : ::xml_schema::type (e, f | ::xml_schema::flags::base, c),
    npc_formation_template_ (this)
  {
    if ((f & ::xml_schema::flags::base) == 0)
    {
      ::xsd::cxx::xml::dom::parser< wchar_t > p (e, true, false, false);
      this->parse (p, f);
    }
  }

  void npc_formation_table::
  parse (::xsd::cxx::xml::dom::parser< wchar_t >& p,
         ::xml_schema::flags f)
  {
    for (; p.more_content (); p.next_content (false))
    {
      const ::xercesc::DOMElement& i (p.cur_element ());
      const ::xsd::cxx::xml::qualified_name< wchar_t > n (
        ::xsd::cxx::xml::dom::name< wchar_t > (i));

      // npc_formation_template
      //
      if (n.name () == L"npc_formation_template" && n.namespace_ ().empty ())
      {
        ::std::unique_ptr< npc_formation_template_type > r (
          npc_formation_template_traits::create (i, f, this));

        this->npc_formation_template_.push_back (::std::move (r));
        continue;
      }

      break;
    }
  }

  npc_formation_table* npc_formation_table::
  _clone (::xml_schema::flags f,
          ::xml_schema::container* c) const
  {
    return new class npc_formation_table (*this, f, c);
  }

  npc_formation_table& npc_formation_table::
  operator= (const npc_formation_table& x)
  {
    if (this != &x)
    {
      static_cast< ::xml_schema::type& > (*this) = x;
      this->npc_formation_template_ = x.npc_formation_template_;
    }

    return *this;
  }

  npc_formation_table::
  ~npc_formation_table ()
  {
  }
}

#include <istream>
#include <xsd/cxx/xml/sax/std-input-source.hxx>
#include <xsd/cxx/tree/error-handler.hxx>

namespace gdt
{
  ::std::unique_ptr< ::gdt::npc_formation_table >
  npc_formation_table_ (const ::std::wstring& u,
                        ::xml_schema::flags f,
                        const ::xml_schema::properties& p)
  {
    ::xsd::cxx::xml::auto_initializer i (
      (f & ::xml_schema::flags::dont_initialize) == 0,
      (f & ::xml_schema::flags::keep_dom) == 0);

    ::xsd::cxx::tree::error_handler< wchar_t > h;

    ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
      ::xsd::cxx::xml::dom::parse< wchar_t > (
        u, h, p, f));

    h.throw_if_failed< ::xsd::cxx::tree::parsing< wchar_t > > ();

    return ::std::unique_ptr< ::gdt::npc_formation_table > (
      ::gdt::npc_formation_table_ (
        std::move (d), f | ::xml_schema::flags::own_dom, p));
  }

  ::std::unique_ptr< ::gdt::npc_formation_table >
  npc_formation_table_ (const ::std::wstring& u,
                        ::xml_schema::error_handler& h,
                        ::xml_schema::flags f,
                        const ::xml_schema::properties& p)
  {
    ::xsd::cxx::xml::auto_initializer i (
      (f & ::xml_schema::flags::dont_initialize) == 0,
      (f & ::xml_schema::flags::keep_dom) == 0);

    ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
      ::xsd::cxx::xml::dom::parse< wchar_t > (
        u, h, p, f));

    if (!d.get ())
      throw ::xsd::cxx::tree::parsing< wchar_t > ();

    return ::std::unique_ptr< ::gdt::npc_formation_table > (
      ::gdt::npc_formation_table_ (
        std::move (d), f | ::xml_schema::flags::own_dom, p));
  }

  ::std::unique_ptr< ::gdt::npc_formation_table >
  npc_formation_table_ (const ::std::wstring& u,
                        ::xercesc::DOMErrorHandler& h,
                        ::xml_schema::flags f,
                        const ::xml_schema::properties& p)
  {
    ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
      ::xsd::cxx::xml::dom::parse< wchar_t > (
        u, h, p, f));

    if (!d.get ())
      throw ::xsd::cxx::tree::parsing< wchar_t > ();

    return ::std::unique_ptr< ::gdt::npc_formation_table > (
      ::gdt::npc_formation_table_ (
        std::move (d), f | ::xml_schema::flags::own_dom, p));
  }

  ::std::unique_ptr< ::gdt::npc_formation_table >
  npc_formation_table_ (::std::istream& is,
                        ::xml_schema::flags f,
                        const ::xml_schema::properties& p)
  {
    ::xsd::cxx::xml::auto_initializer i (
      (f & ::xml_schema::flags::dont_initialize) == 0,
      (f & ::xml_schema::flags::keep_dom) == 0);

    ::xsd::cxx::xml::sax::std_input_source isrc (is);
    return ::gdt::npc_formation_table_ (isrc, f, p);
  }

  ::std::unique_ptr< ::gdt::npc_formation_table >
  npc_formation_table_ (::std::istream& is,
                        ::xml_schema::error_handler& h,
                        ::xml_schema::flags f,
                        const ::xml_schema::properties& p)
  {
    ::xsd::cxx::xml::auto_initializer i (
      (f & ::xml_schema::flags::dont_initialize) == 0,
      (f & ::xml_schema::flags::keep_dom) == 0);

    ::xsd::cxx::xml::sax::std_input_source isrc (is);
    return ::gdt::npc_formation_table_ (isrc, h, f, p);
  }

  ::std::unique_ptr< ::gdt::npc_formation_table >
  npc_formation_table_ (::std::istream& is,
                        ::xercesc::DOMErrorHandler& h,
                        ::xml_schema::flags f,
                        const ::xml_schema::properties& p)
  {
    ::xsd::cxx::xml::sax::std_input_source isrc (is);
    return ::gdt::npc_formation_table_ (isrc, h, f, p);
  }

  ::std::unique_ptr< ::gdt::npc_formation_table >
  npc_formation_table_ (::std::istream& is,
                        const ::std::wstring& sid,
                        ::xml_schema::flags f,
                        const ::xml_schema::properties& p)
  {
    ::xsd::cxx::xml::auto_initializer i (
      (f & ::xml_schema::flags::dont_initialize) == 0,
      (f & ::xml_schema::flags::keep_dom) == 0);

    ::xsd::cxx::xml::sax::std_input_source isrc (is, sid);
    return ::gdt::npc_formation_table_ (isrc, f, p);
  }

  ::std::unique_ptr< ::gdt::npc_formation_table >
  npc_formation_table_ (::std::istream& is,
                        const ::std::wstring& sid,
                        ::xml_schema::error_handler& h,
                        ::xml_schema::flags f,
                        const ::xml_schema::properties& p)
  {
    ::xsd::cxx::xml::auto_initializer i (
      (f & ::xml_schema::flags::dont_initialize) == 0,
      (f & ::xml_schema::flags::keep_dom) == 0);

    ::xsd::cxx::xml::sax::std_input_source isrc (is, sid);
    return ::gdt::npc_formation_table_ (isrc, h, f, p);
  }

  ::std::unique_ptr< ::gdt::npc_formation_table >
  npc_formation_table_ (::std::istream& is,
                        const ::std::wstring& sid,
                        ::xercesc::DOMErrorHandler& h,
                        ::xml_schema::flags f,
                        const ::xml_schema::properties& p)
  {
    ::xsd::cxx::xml::sax::std_input_source isrc (is, sid);
    return ::gdt::npc_formation_table_ (isrc, h, f, p);
  }

  ::std::unique_ptr< ::gdt::npc_formation_table >
  npc_formation_table_ (::xercesc::InputSource& i,
                        ::xml_schema::flags f,
                        const ::xml_schema::properties& p)
  {
    ::xsd::cxx::tree::error_handler< wchar_t > h;

    ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
      ::xsd::cxx::xml::dom::parse< wchar_t > (
        i, h, p, f));

    h.throw_if_failed< ::xsd::cxx::tree::parsing< wchar_t > > ();

    return ::std::unique_ptr< ::gdt::npc_formation_table > (
      ::gdt::npc_formation_table_ (
        std::move (d), f | ::xml_schema::flags::own_dom, p));
  }

  ::std::unique_ptr< ::gdt::npc_formation_table >
  npc_formation_table_ (::xercesc::InputSource& i,
                        ::xml_schema::error_handler& h,
                        ::xml_schema::flags f,
                        const ::xml_schema::properties& p)
  {
    ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
      ::xsd::cxx::xml::dom::parse< wchar_t > (
        i, h, p, f));

    if (!d.get ())
      throw ::xsd::cxx::tree::parsing< wchar_t > ();

    return ::std::unique_ptr< ::gdt::npc_formation_table > (
      ::gdt::npc_formation_table_ (
        std::move (d), f | ::xml_schema::flags::own_dom, p));
  }

  ::std::unique_ptr< ::gdt::npc_formation_table >
  npc_formation_table_ (::xercesc::InputSource& i,
                        ::xercesc::DOMErrorHandler& h,
                        ::xml_schema::flags f,
                        const ::xml_schema::properties& p)
  {
    ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
      ::xsd::cxx::xml::dom::parse< wchar_t > (
        i, h, p, f));

    if (!d.get ())
      throw ::xsd::cxx::tree::parsing< wchar_t > ();

    return ::std::unique_ptr< ::gdt::npc_formation_table > (
      ::gdt::npc_formation_table_ (
        std::move (d), f | ::xml_schema::flags::own_dom, p));
  }

  ::std::unique_ptr< ::gdt::npc_formation_table >
  npc_formation_table_ (const ::xercesc::DOMDocument& doc,
                        ::xml_schema::flags f,
                        const ::xml_schema::properties& p)
  {
    if (f & ::xml_schema::flags::keep_dom)
    {
      ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
        static_cast< ::xercesc::DOMDocument* > (doc.cloneNode (true)));

      return ::std::unique_ptr< ::gdt::npc_formation_table > (
        ::gdt::npc_formation_table_ (
          std::move (d), f | ::xml_schema::flags::own_dom, p));
    }

    const ::xercesc::DOMElement& e (*doc.getDocumentElement ());
    const ::xsd::cxx::xml::qualified_name< wchar_t > n (
      ::xsd::cxx::xml::dom::name< wchar_t > (e));

    if (n.name () == L"npc_formation_table" &&
        n.namespace_ () == L"")
    {
      ::std::unique_ptr< ::gdt::npc_formation_table > r (
        ::xsd::cxx::tree::traits< ::gdt::npc_formation_table, wchar_t >::create (
          e, f, 0));
      return r;
    }

    throw ::xsd::cxx::tree::unexpected_element < wchar_t > (
      n.name (),
      n.namespace_ (),
      L"npc_formation_table",
      L"");
  }

  ::std::unique_ptr< ::gdt::npc_formation_table >
  npc_formation_table_ (::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d,
                        ::xml_schema::flags f,
                        const ::xml_schema::properties&)
  {
    ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > c (
      ((f & ::xml_schema::flags::keep_dom) &&
       !(f & ::xml_schema::flags::own_dom))
      ? static_cast< ::xercesc::DOMDocument* > (d->cloneNode (true))
      : 0);

    ::xercesc::DOMDocument& doc (c.get () ? *c : *d);
    const ::xercesc::DOMElement& e (*doc.getDocumentElement ());

    const ::xsd::cxx::xml::qualified_name< wchar_t > n (
      ::xsd::cxx::xml::dom::name< wchar_t > (e));

    if (f & ::xml_schema::flags::keep_dom)
      doc.setUserData (::xml_schema::dom::tree_node_key,
                       (c.get () ? &c : &d),
                       0);

    if (n.name () == L"npc_formation_table" &&
        n.namespace_ () == L"")
    {
      ::std::unique_ptr< ::gdt::npc_formation_table > r (
        ::xsd::cxx::tree::traits< ::gdt::npc_formation_table, wchar_t >::create (
          e, f, 0));
      return r;
    }

    throw ::xsd::cxx::tree::unexpected_element < wchar_t > (
      n.name (),
      n.namespace_ (),
      L"npc_formation_table",
      L"");
  }
}

#include <ostream>
#include <xsd/cxx/tree/error-handler.hxx>
#include <xsd/cxx/xml/dom/serialization-source.hxx>

namespace gdt
{
  void
  npc_formation_table_ (::std::ostream& o,
                        const ::gdt::npc_formation_table& s,
                        const ::xml_schema::namespace_infomap& m,
                        const ::std::wstring& e,
                        ::xml_schema::flags f)
  {
    ::xsd::cxx::xml::auto_initializer i (
      (f & ::xml_schema::flags::dont_initialize) == 0);

    ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
      ::gdt::npc_formation_table_ (s, m, f));

    ::xsd::cxx::tree::error_handler< wchar_t > h;

    ::xsd::cxx::xml::dom::ostream_format_target t (o);
    if (!::xsd::cxx::xml::dom::serialize (t, *d, e, h, f))
    {
      h.throw_if_failed< ::xsd::cxx::tree::serialization< wchar_t > > ();
    }
  }

  void
  npc_formation_table_ (::std::ostream& o,
                        const ::gdt::npc_formation_table& s,
                        ::xml_schema::error_handler& h,
                        const ::xml_schema::namespace_infomap& m,
                        const ::std::wstring& e,
                        ::xml_schema::flags f)
  {
    ::xsd::cxx::xml::auto_initializer i (
      (f & ::xml_schema::flags::dont_initialize) == 0);

    ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
      ::gdt::npc_formation_table_ (s, m, f));
    ::xsd::cxx::xml::dom::ostream_format_target t (o);
    if (!::xsd::cxx::xml::dom::serialize (t, *d, e, h, f))
    {
      throw ::xsd::cxx::tree::serialization< wchar_t > ();
    }
  }

  void
  npc_formation_table_ (::std::ostream& o,
                        const ::gdt::npc_formation_table& s,
                        ::xercesc::DOMErrorHandler& h,
                        const ::xml_schema::namespace_infomap& m,
                        const ::std::wstring& e,
                        ::xml_schema::flags f)
  {
    ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
      ::gdt::npc_formation_table_ (s, m, f));
    ::xsd::cxx::xml::dom::ostream_format_target t (o);
    if (!::xsd::cxx::xml::dom::serialize (t, *d, e, h, f))
    {
      throw ::xsd::cxx::tree::serialization< wchar_t > ();
    }
  }

  void
  npc_formation_table_ (::xercesc::XMLFormatTarget& t,
                        const ::gdt::npc_formation_table& s,
                        const ::xml_schema::namespace_infomap& m,
                        const ::std::wstring& e,
                        ::xml_schema::flags f)
  {
    ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
      ::gdt::npc_formation_table_ (s, m, f));

    ::xsd::cxx::tree::error_handler< wchar_t > h;

    if (!::xsd::cxx::xml::dom::serialize (t, *d, e, h, f))
    {
      h.throw_if_failed< ::xsd::cxx::tree::serialization< wchar_t > > ();
    }
  }

  void
  npc_formation_table_ (::xercesc::XMLFormatTarget& t,
                        const ::gdt::npc_formation_table& s,
                        ::xml_schema::error_handler& h,
                        const ::xml_schema::namespace_infomap& m,
                        const ::std::wstring& e,
                        ::xml_schema::flags f)
  {
    ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
      ::gdt::npc_formation_table_ (s, m, f));
    if (!::xsd::cxx::xml::dom::serialize (t, *d, e, h, f))
    {
      throw ::xsd::cxx::tree::serialization< wchar_t > ();
    }
  }

  void
  npc_formation_table_ (::xercesc::XMLFormatTarget& t,
                        const ::gdt::npc_formation_table& s,
                        ::xercesc::DOMErrorHandler& h,
                        const ::xml_schema::namespace_infomap& m,
                        const ::std::wstring& e,
                        ::xml_schema::flags f)
  {
    ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
      ::gdt::npc_formation_table_ (s, m, f));
    if (!::xsd::cxx::xml::dom::serialize (t, *d, e, h, f))
    {
      throw ::xsd::cxx::tree::serialization< wchar_t > ();
    }
  }

  void
  npc_formation_table_ (::xercesc::DOMDocument& d,
                        const ::gdt::npc_formation_table& s,
                        ::xml_schema::flags)
  {
    ::xercesc::DOMElement& e (*d.getDocumentElement ());
    const ::xsd::cxx::xml::qualified_name< wchar_t > n (
      ::xsd::cxx::xml::dom::name< wchar_t > (e));

    if (n.name () == L"npc_formation_table" &&
        n.namespace_ () == L"")
    {
      e << s;
    }
    else
    {
      throw ::xsd::cxx::tree::unexpected_element < wchar_t > (
        n.name (),
        n.namespace_ (),
        L"npc_formation_table",
        L"");
    }
  }

  ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument >
  npc_formation_table_ (const ::gdt::npc_formation_table& s,
                        const ::xml_schema::namespace_infomap& m,
                        ::xml_schema::flags f)
  {
    ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
      ::xsd::cxx::xml::dom::serialize< wchar_t > (
        L"npc_formation_table",
        L"",
        m, f));

    ::gdt::npc_formation_table_ (*d, s, f);
    return d;
  }

  void
  operator<< (::xercesc::DOMElement& e, const npc_formation_t& i)
  {
    e << static_cast< const ::xml_schema::type& > (i);

    // leader_npc_code
    //
    {
      ::xercesc::DOMAttr& a (
        ::xsd::cxx::xml::dom::create_attribute (
          L"leader_npc_code",
          e));

      a << i.leader_npc_code ();
    }

    // member_npc_code
    //
    {
      ::xercesc::DOMAttr& a (
        ::xsd::cxx::xml::dom::create_attribute (
          L"member_npc_code",
          e));

      a << i.member_npc_code ();
    }

    // max_distance
    //
    {
      ::xercesc::DOMAttr& a (
        ::xsd::cxx::xml::dom::create_attribute (
          L"max_distance",
          e));

      a << i.max_distance ();
    }

    // angle
    //
    {
      ::xercesc::DOMAttr& a (
        ::xsd::cxx::xml::dom::create_attribute (
          L"angle",
          e));

      a << i.angle ();
    }

    // react_type
    //
    {
      ::xercesc::DOMAttr& a (
        ::xsd::cxx::xml::dom::create_attribute (
          L"react_type",
          e));

      a << i.react_type ();
    }
  }

  void
  operator<< (::xercesc::DOMElement& e, const npc_formation_table& i)
  {
    e << static_cast< const ::xml_schema::type& > (i);

    // npc_formation_template
    //
    for (npc_formation_table::npc_formation_template_const_iterator
         b (i.npc_formation_template ().begin ()), n (i.npc_formation_template ().end ());
         b != n; ++b)
    {
      ::xercesc::DOMElement& s (
        ::xsd::cxx::xml::dom::create_element (
          L"npc_formation_template",
          e));

      s << *b;
    }
  }
}

#include <xsd/cxx/post.hxx>

// Begin epilogue.
//
//
// End epilogue.

