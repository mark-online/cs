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

#include "quest_probe_mission_table.hxx"

#include <xsd/cxx/xml/dom/parsing-source.hxx>

namespace gdt
{
  // quest_probe_mission_t
  //

  quest_probe_mission_t::
  quest_probe_mission_t ()
  : ::xml_schema::type (),
    mission_code_ (this),
    map_code_ (this),
    marker_code_1_ (this),
    marker_code_2_ (this),
    marker_code_3_ (this)
  {
  }

  quest_probe_mission_t::
  quest_probe_mission_t (const mission_code_type& mission_code,
                         const map_code_type& map_code,
                         const marker_code_1_type& marker_code_1,
                         const marker_code_2_type& marker_code_2,
                         const marker_code_3_type& marker_code_3)
  : ::xml_schema::type (),
    mission_code_ (mission_code, this),
    map_code_ (map_code, this),
    marker_code_1_ (marker_code_1, this),
    marker_code_2_ (marker_code_2, this),
    marker_code_3_ (marker_code_3, this)
  {
  }

  quest_probe_mission_t::
  quest_probe_mission_t (const quest_probe_mission_t& x,
                         ::xml_schema::flags f,
                         ::xml_schema::container* c)
  : ::xml_schema::type (x, f, c),
    mission_code_ (x.mission_code_, f, this),
    map_code_ (x.map_code_, f, this),
    marker_code_1_ (x.marker_code_1_, f, this),
    marker_code_2_ (x.marker_code_2_, f, this),
    marker_code_3_ (x.marker_code_3_, f, this)
  {
  }

  quest_probe_mission_t::
  quest_probe_mission_t (const ::xercesc::DOMElement& e,
                         ::xml_schema::flags f,
                         ::xml_schema::container* c)
  : ::xml_schema::type (e, f | ::xml_schema::flags::base, c),
    mission_code_ (this),
    map_code_ (this),
    marker_code_1_ (this),
    marker_code_2_ (this),
    marker_code_3_ (this)
  {
    if ((f & ::xml_schema::flags::base) == 0)
    {
      ::xsd::cxx::xml::dom::parser< wchar_t > p (e, false, false, true);
      this->parse (p, f);
    }
  }

  void quest_probe_mission_t::
  parse (::xsd::cxx::xml::dom::parser< wchar_t >& p,
         ::xml_schema::flags f)
  {
    while (p.more_attributes ())
    {
      const ::xercesc::DOMAttr& i (p.next_attribute ());
      const ::xsd::cxx::xml::qualified_name< wchar_t > n (
        ::xsd::cxx::xml::dom::name< wchar_t > (i));

      if (n.name () == L"mission_code" && n.namespace_ ().empty ())
      {
        this->mission_code_.set (mission_code_traits::create (i, f, this));
        continue;
      }

      if (n.name () == L"map_code" && n.namespace_ ().empty ())
      {
        this->map_code_.set (map_code_traits::create (i, f, this));
        continue;
      }

      if (n.name () == L"marker_code_1" && n.namespace_ ().empty ())
      {
        this->marker_code_1_.set (marker_code_1_traits::create (i, f, this));
        continue;
      }

      if (n.name () == L"marker_code_2" && n.namespace_ ().empty ())
      {
        this->marker_code_2_.set (marker_code_2_traits::create (i, f, this));
        continue;
      }

      if (n.name () == L"marker_code_3" && n.namespace_ ().empty ())
      {
        this->marker_code_3_.set (marker_code_3_traits::create (i, f, this));
        continue;
      }
    }

    if (!mission_code_.present ())
    {
      throw ::xsd::cxx::tree::expected_attribute< wchar_t > (
        L"mission_code",
        L"");
    }

    if (!map_code_.present ())
    {
      throw ::xsd::cxx::tree::expected_attribute< wchar_t > (
        L"map_code",
        L"");
    }

    if (!marker_code_1_.present ())
    {
      throw ::xsd::cxx::tree::expected_attribute< wchar_t > (
        L"marker_code_1",
        L"");
    }

    if (!marker_code_2_.present ())
    {
      throw ::xsd::cxx::tree::expected_attribute< wchar_t > (
        L"marker_code_2",
        L"");
    }

    if (!marker_code_3_.present ())
    {
      throw ::xsd::cxx::tree::expected_attribute< wchar_t > (
        L"marker_code_3",
        L"");
    }
  }

  quest_probe_mission_t* quest_probe_mission_t::
  _clone (::xml_schema::flags f,
          ::xml_schema::container* c) const
  {
    return new class quest_probe_mission_t (*this, f, c);
  }

  quest_probe_mission_t& quest_probe_mission_t::
  operator= (const quest_probe_mission_t& x)
  {
    if (this != &x)
    {
      static_cast< ::xml_schema::type& > (*this) = x;
      this->mission_code_ = x.mission_code_;
      this->map_code_ = x.map_code_;
      this->marker_code_1_ = x.marker_code_1_;
      this->marker_code_2_ = x.marker_code_2_;
      this->marker_code_3_ = x.marker_code_3_;
    }

    return *this;
  }

  quest_probe_mission_t::
  ~quest_probe_mission_t ()
  {
  }

  // quest_probe_mission_table
  //

  quest_probe_mission_table::
  quest_probe_mission_table ()
  : ::xml_schema::type (),
    quest_probe_mission_template_ (this)
  {
  }

  quest_probe_mission_table::
  quest_probe_mission_table (const quest_probe_mission_table& x,
                             ::xml_schema::flags f,
                             ::xml_schema::container* c)
  : ::xml_schema::type (x, f, c),
    quest_probe_mission_template_ (x.quest_probe_mission_template_, f, this)
  {
  }

  quest_probe_mission_table::
  quest_probe_mission_table (const ::xercesc::DOMElement& e,
                             ::xml_schema::flags f,
                             ::xml_schema::container* c)
  : ::xml_schema::type (e, f | ::xml_schema::flags::base, c),
    quest_probe_mission_template_ (this)
  {
    if ((f & ::xml_schema::flags::base) == 0)
    {
      ::xsd::cxx::xml::dom::parser< wchar_t > p (e, true, false, false);
      this->parse (p, f);
    }
  }

  void quest_probe_mission_table::
  parse (::xsd::cxx::xml::dom::parser< wchar_t >& p,
         ::xml_schema::flags f)
  {
    for (; p.more_content (); p.next_content (false))
    {
      const ::xercesc::DOMElement& i (p.cur_element ());
      const ::xsd::cxx::xml::qualified_name< wchar_t > n (
        ::xsd::cxx::xml::dom::name< wchar_t > (i));

      // quest_probe_mission_template
      //
      if (n.name () == L"quest_probe_mission_template" && n.namespace_ ().empty ())
      {
        ::std::unique_ptr< quest_probe_mission_template_type > r (
          quest_probe_mission_template_traits::create (i, f, this));

        this->quest_probe_mission_template_.push_back (::std::move (r));
        continue;
      }

      break;
    }
  }

  quest_probe_mission_table* quest_probe_mission_table::
  _clone (::xml_schema::flags f,
          ::xml_schema::container* c) const
  {
    return new class quest_probe_mission_table (*this, f, c);
  }

  quest_probe_mission_table& quest_probe_mission_table::
  operator= (const quest_probe_mission_table& x)
  {
    if (this != &x)
    {
      static_cast< ::xml_schema::type& > (*this) = x;
      this->quest_probe_mission_template_ = x.quest_probe_mission_template_;
    }

    return *this;
  }

  quest_probe_mission_table::
  ~quest_probe_mission_table ()
  {
  }
}

#include <istream>
#include <xsd/cxx/xml/sax/std-input-source.hxx>
#include <xsd/cxx/tree/error-handler.hxx>

namespace gdt
{
  ::std::unique_ptr< ::gdt::quest_probe_mission_table >
  quest_probe_mission_table_ (const ::std::wstring& u,
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

    return ::std::unique_ptr< ::gdt::quest_probe_mission_table > (
      ::gdt::quest_probe_mission_table_ (
        std::move (d), f | ::xml_schema::flags::own_dom, p));
  }

  ::std::unique_ptr< ::gdt::quest_probe_mission_table >
  quest_probe_mission_table_ (const ::std::wstring& u,
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

    return ::std::unique_ptr< ::gdt::quest_probe_mission_table > (
      ::gdt::quest_probe_mission_table_ (
        std::move (d), f | ::xml_schema::flags::own_dom, p));
  }

  ::std::unique_ptr< ::gdt::quest_probe_mission_table >
  quest_probe_mission_table_ (const ::std::wstring& u,
                              ::xercesc::DOMErrorHandler& h,
                              ::xml_schema::flags f,
                              const ::xml_schema::properties& p)
  {
    ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
      ::xsd::cxx::xml::dom::parse< wchar_t > (
        u, h, p, f));

    if (!d.get ())
      throw ::xsd::cxx::tree::parsing< wchar_t > ();

    return ::std::unique_ptr< ::gdt::quest_probe_mission_table > (
      ::gdt::quest_probe_mission_table_ (
        std::move (d), f | ::xml_schema::flags::own_dom, p));
  }

  ::std::unique_ptr< ::gdt::quest_probe_mission_table >
  quest_probe_mission_table_ (::std::istream& is,
                              ::xml_schema::flags f,
                              const ::xml_schema::properties& p)
  {
    ::xsd::cxx::xml::auto_initializer i (
      (f & ::xml_schema::flags::dont_initialize) == 0,
      (f & ::xml_schema::flags::keep_dom) == 0);

    ::xsd::cxx::xml::sax::std_input_source isrc (is);
    return ::gdt::quest_probe_mission_table_ (isrc, f, p);
  }

  ::std::unique_ptr< ::gdt::quest_probe_mission_table >
  quest_probe_mission_table_ (::std::istream& is,
                              ::xml_schema::error_handler& h,
                              ::xml_schema::flags f,
                              const ::xml_schema::properties& p)
  {
    ::xsd::cxx::xml::auto_initializer i (
      (f & ::xml_schema::flags::dont_initialize) == 0,
      (f & ::xml_schema::flags::keep_dom) == 0);

    ::xsd::cxx::xml::sax::std_input_source isrc (is);
    return ::gdt::quest_probe_mission_table_ (isrc, h, f, p);
  }

  ::std::unique_ptr< ::gdt::quest_probe_mission_table >
  quest_probe_mission_table_ (::std::istream& is,
                              ::xercesc::DOMErrorHandler& h,
                              ::xml_schema::flags f,
                              const ::xml_schema::properties& p)
  {
    ::xsd::cxx::xml::sax::std_input_source isrc (is);
    return ::gdt::quest_probe_mission_table_ (isrc, h, f, p);
  }

  ::std::unique_ptr< ::gdt::quest_probe_mission_table >
  quest_probe_mission_table_ (::std::istream& is,
                              const ::std::wstring& sid,
                              ::xml_schema::flags f,
                              const ::xml_schema::properties& p)
  {
    ::xsd::cxx::xml::auto_initializer i (
      (f & ::xml_schema::flags::dont_initialize) == 0,
      (f & ::xml_schema::flags::keep_dom) == 0);

    ::xsd::cxx::xml::sax::std_input_source isrc (is, sid);
    return ::gdt::quest_probe_mission_table_ (isrc, f, p);
  }

  ::std::unique_ptr< ::gdt::quest_probe_mission_table >
  quest_probe_mission_table_ (::std::istream& is,
                              const ::std::wstring& sid,
                              ::xml_schema::error_handler& h,
                              ::xml_schema::flags f,
                              const ::xml_schema::properties& p)
  {
    ::xsd::cxx::xml::auto_initializer i (
      (f & ::xml_schema::flags::dont_initialize) == 0,
      (f & ::xml_schema::flags::keep_dom) == 0);

    ::xsd::cxx::xml::sax::std_input_source isrc (is, sid);
    return ::gdt::quest_probe_mission_table_ (isrc, h, f, p);
  }

  ::std::unique_ptr< ::gdt::quest_probe_mission_table >
  quest_probe_mission_table_ (::std::istream& is,
                              const ::std::wstring& sid,
                              ::xercesc::DOMErrorHandler& h,
                              ::xml_schema::flags f,
                              const ::xml_schema::properties& p)
  {
    ::xsd::cxx::xml::sax::std_input_source isrc (is, sid);
    return ::gdt::quest_probe_mission_table_ (isrc, h, f, p);
  }

  ::std::unique_ptr< ::gdt::quest_probe_mission_table >
  quest_probe_mission_table_ (::xercesc::InputSource& i,
                              ::xml_schema::flags f,
                              const ::xml_schema::properties& p)
  {
    ::xsd::cxx::tree::error_handler< wchar_t > h;

    ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
      ::xsd::cxx::xml::dom::parse< wchar_t > (
        i, h, p, f));

    h.throw_if_failed< ::xsd::cxx::tree::parsing< wchar_t > > ();

    return ::std::unique_ptr< ::gdt::quest_probe_mission_table > (
      ::gdt::quest_probe_mission_table_ (
        std::move (d), f | ::xml_schema::flags::own_dom, p));
  }

  ::std::unique_ptr< ::gdt::quest_probe_mission_table >
  quest_probe_mission_table_ (::xercesc::InputSource& i,
                              ::xml_schema::error_handler& h,
                              ::xml_schema::flags f,
                              const ::xml_schema::properties& p)
  {
    ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
      ::xsd::cxx::xml::dom::parse< wchar_t > (
        i, h, p, f));

    if (!d.get ())
      throw ::xsd::cxx::tree::parsing< wchar_t > ();

    return ::std::unique_ptr< ::gdt::quest_probe_mission_table > (
      ::gdt::quest_probe_mission_table_ (
        std::move (d), f | ::xml_schema::flags::own_dom, p));
  }

  ::std::unique_ptr< ::gdt::quest_probe_mission_table >
  quest_probe_mission_table_ (::xercesc::InputSource& i,
                              ::xercesc::DOMErrorHandler& h,
                              ::xml_schema::flags f,
                              const ::xml_schema::properties& p)
  {
    ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
      ::xsd::cxx::xml::dom::parse< wchar_t > (
        i, h, p, f));

    if (!d.get ())
      throw ::xsd::cxx::tree::parsing< wchar_t > ();

    return ::std::unique_ptr< ::gdt::quest_probe_mission_table > (
      ::gdt::quest_probe_mission_table_ (
        std::move (d), f | ::xml_schema::flags::own_dom, p));
  }

  ::std::unique_ptr< ::gdt::quest_probe_mission_table >
  quest_probe_mission_table_ (const ::xercesc::DOMDocument& doc,
                              ::xml_schema::flags f,
                              const ::xml_schema::properties& p)
  {
    if (f & ::xml_schema::flags::keep_dom)
    {
      ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
        static_cast< ::xercesc::DOMDocument* > (doc.cloneNode (true)));

      return ::std::unique_ptr< ::gdt::quest_probe_mission_table > (
        ::gdt::quest_probe_mission_table_ (
          std::move (d), f | ::xml_schema::flags::own_dom, p));
    }

    const ::xercesc::DOMElement& e (*doc.getDocumentElement ());
    const ::xsd::cxx::xml::qualified_name< wchar_t > n (
      ::xsd::cxx::xml::dom::name< wchar_t > (e));

    if (n.name () == L"quest_probe_mission_table" &&
        n.namespace_ () == L"")
    {
      ::std::unique_ptr< ::gdt::quest_probe_mission_table > r (
        ::xsd::cxx::tree::traits< ::gdt::quest_probe_mission_table, wchar_t >::create (
          e, f, 0));
      return r;
    }

    throw ::xsd::cxx::tree::unexpected_element < wchar_t > (
      n.name (),
      n.namespace_ (),
      L"quest_probe_mission_table",
      L"");
  }

  ::std::unique_ptr< ::gdt::quest_probe_mission_table >
  quest_probe_mission_table_ (::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d,
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

    if (n.name () == L"quest_probe_mission_table" &&
        n.namespace_ () == L"")
    {
      ::std::unique_ptr< ::gdt::quest_probe_mission_table > r (
        ::xsd::cxx::tree::traits< ::gdt::quest_probe_mission_table, wchar_t >::create (
          e, f, 0));
      return r;
    }

    throw ::xsd::cxx::tree::unexpected_element < wchar_t > (
      n.name (),
      n.namespace_ (),
      L"quest_probe_mission_table",
      L"");
  }
}

#include <ostream>
#include <xsd/cxx/tree/error-handler.hxx>
#include <xsd/cxx/xml/dom/serialization-source.hxx>

namespace gdt
{
  void
  quest_probe_mission_table_ (::std::ostream& o,
                              const ::gdt::quest_probe_mission_table& s,
                              const ::xml_schema::namespace_infomap& m,
                              const ::std::wstring& e,
                              ::xml_schema::flags f)
  {
    ::xsd::cxx::xml::auto_initializer i (
      (f & ::xml_schema::flags::dont_initialize) == 0);

    ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
      ::gdt::quest_probe_mission_table_ (s, m, f));

    ::xsd::cxx::tree::error_handler< wchar_t > h;

    ::xsd::cxx::xml::dom::ostream_format_target t (o);
    if (!::xsd::cxx::xml::dom::serialize (t, *d, e, h, f))
    {
      h.throw_if_failed< ::xsd::cxx::tree::serialization< wchar_t > > ();
    }
  }

  void
  quest_probe_mission_table_ (::std::ostream& o,
                              const ::gdt::quest_probe_mission_table& s,
                              ::xml_schema::error_handler& h,
                              const ::xml_schema::namespace_infomap& m,
                              const ::std::wstring& e,
                              ::xml_schema::flags f)
  {
    ::xsd::cxx::xml::auto_initializer i (
      (f & ::xml_schema::flags::dont_initialize) == 0);

    ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
      ::gdt::quest_probe_mission_table_ (s, m, f));
    ::xsd::cxx::xml::dom::ostream_format_target t (o);
    if (!::xsd::cxx::xml::dom::serialize (t, *d, e, h, f))
    {
      throw ::xsd::cxx::tree::serialization< wchar_t > ();
    }
  }

  void
  quest_probe_mission_table_ (::std::ostream& o,
                              const ::gdt::quest_probe_mission_table& s,
                              ::xercesc::DOMErrorHandler& h,
                              const ::xml_schema::namespace_infomap& m,
                              const ::std::wstring& e,
                              ::xml_schema::flags f)
  {
    ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
      ::gdt::quest_probe_mission_table_ (s, m, f));
    ::xsd::cxx::xml::dom::ostream_format_target t (o);
    if (!::xsd::cxx::xml::dom::serialize (t, *d, e, h, f))
    {
      throw ::xsd::cxx::tree::serialization< wchar_t > ();
    }
  }

  void
  quest_probe_mission_table_ (::xercesc::XMLFormatTarget& t,
                              const ::gdt::quest_probe_mission_table& s,
                              const ::xml_schema::namespace_infomap& m,
                              const ::std::wstring& e,
                              ::xml_schema::flags f)
  {
    ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
      ::gdt::quest_probe_mission_table_ (s, m, f));

    ::xsd::cxx::tree::error_handler< wchar_t > h;

    if (!::xsd::cxx::xml::dom::serialize (t, *d, e, h, f))
    {
      h.throw_if_failed< ::xsd::cxx::tree::serialization< wchar_t > > ();
    }
  }

  void
  quest_probe_mission_table_ (::xercesc::XMLFormatTarget& t,
                              const ::gdt::quest_probe_mission_table& s,
                              ::xml_schema::error_handler& h,
                              const ::xml_schema::namespace_infomap& m,
                              const ::std::wstring& e,
                              ::xml_schema::flags f)
  {
    ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
      ::gdt::quest_probe_mission_table_ (s, m, f));
    if (!::xsd::cxx::xml::dom::serialize (t, *d, e, h, f))
    {
      throw ::xsd::cxx::tree::serialization< wchar_t > ();
    }
  }

  void
  quest_probe_mission_table_ (::xercesc::XMLFormatTarget& t,
                              const ::gdt::quest_probe_mission_table& s,
                              ::xercesc::DOMErrorHandler& h,
                              const ::xml_schema::namespace_infomap& m,
                              const ::std::wstring& e,
                              ::xml_schema::flags f)
  {
    ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
      ::gdt::quest_probe_mission_table_ (s, m, f));
    if (!::xsd::cxx::xml::dom::serialize (t, *d, e, h, f))
    {
      throw ::xsd::cxx::tree::serialization< wchar_t > ();
    }
  }

  void
  quest_probe_mission_table_ (::xercesc::DOMDocument& d,
                              const ::gdt::quest_probe_mission_table& s,
                              ::xml_schema::flags)
  {
    ::xercesc::DOMElement& e (*d.getDocumentElement ());
    const ::xsd::cxx::xml::qualified_name< wchar_t > n (
      ::xsd::cxx::xml::dom::name< wchar_t > (e));

    if (n.name () == L"quest_probe_mission_table" &&
        n.namespace_ () == L"")
    {
      e << s;
    }
    else
    {
      throw ::xsd::cxx::tree::unexpected_element < wchar_t > (
        n.name (),
        n.namespace_ (),
        L"quest_probe_mission_table",
        L"");
    }
  }

  ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument >
  quest_probe_mission_table_ (const ::gdt::quest_probe_mission_table& s,
                              const ::xml_schema::namespace_infomap& m,
                              ::xml_schema::flags f)
  {
    ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
      ::xsd::cxx::xml::dom::serialize< wchar_t > (
        L"quest_probe_mission_table",
        L"",
        m, f));

    ::gdt::quest_probe_mission_table_ (*d, s, f);
    return d;
  }

  void
  operator<< (::xercesc::DOMElement& e, const quest_probe_mission_t& i)
  {
    e << static_cast< const ::xml_schema::type& > (i);

    // mission_code
    //
    {
      ::xercesc::DOMAttr& a (
        ::xsd::cxx::xml::dom::create_attribute (
          L"mission_code",
          e));

      a << i.mission_code ();
    }

    // map_code
    //
    {
      ::xercesc::DOMAttr& a (
        ::xsd::cxx::xml::dom::create_attribute (
          L"map_code",
          e));

      a << i.map_code ();
    }

    // marker_code_1
    //
    {
      ::xercesc::DOMAttr& a (
        ::xsd::cxx::xml::dom::create_attribute (
          L"marker_code_1",
          e));

      a << i.marker_code_1 ();
    }

    // marker_code_2
    //
    {
      ::xercesc::DOMAttr& a (
        ::xsd::cxx::xml::dom::create_attribute (
          L"marker_code_2",
          e));

      a << i.marker_code_2 ();
    }

    // marker_code_3
    //
    {
      ::xercesc::DOMAttr& a (
        ::xsd::cxx::xml::dom::create_attribute (
          L"marker_code_3",
          e));

      a << i.marker_code_3 ();
    }
  }

  void
  operator<< (::xercesc::DOMElement& e, const quest_probe_mission_table& i)
  {
    e << static_cast< const ::xml_schema::type& > (i);

    // quest_probe_mission_template
    //
    for (quest_probe_mission_table::quest_probe_mission_template_const_iterator
         b (i.quest_probe_mission_template ().begin ()), n (i.quest_probe_mission_template ().end ());
         b != n; ++b)
    {
      ::xercesc::DOMElement& s (
        ::xsd::cxx::xml::dom::create_element (
          L"quest_probe_mission_template",
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

