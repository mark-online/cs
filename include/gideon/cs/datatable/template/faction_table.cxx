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

#include "faction_table.hxx"

#include <xsd/cxx/xml/dom/parsing-source.hxx>

namespace gdt
{
  // faction_t
  //

  faction_t::
  faction_t ()
  : ::xml_schema::type (),
    faction_code_ (this),
    our_mask_ (this),
    friendly_mask_ (this),
    hostile_mask_ (this),
    friendly_factions_ (this),
    hostile_factions_ (this)
  {
  }

  faction_t::
  faction_t (const faction_code_type& faction_code,
             const our_mask_type& our_mask,
             const friendly_mask_type& friendly_mask,
             const hostile_mask_type& hostile_mask)
  : ::xml_schema::type (),
    faction_code_ (faction_code, this),
    our_mask_ (our_mask, this),
    friendly_mask_ (friendly_mask, this),
    hostile_mask_ (hostile_mask, this),
    friendly_factions_ (this),
    hostile_factions_ (this)
  {
  }

  faction_t::
  faction_t (const faction_t& x,
             ::xml_schema::flags f,
             ::xml_schema::container* c)
  : ::xml_schema::type (x, f, c),
    faction_code_ (x.faction_code_, f, this),
    our_mask_ (x.our_mask_, f, this),
    friendly_mask_ (x.friendly_mask_, f, this),
    hostile_mask_ (x.hostile_mask_, f, this),
    friendly_factions_ (x.friendly_factions_, f, this),
    hostile_factions_ (x.hostile_factions_, f, this)
  {
  }

  faction_t::
  faction_t (const ::xercesc::DOMElement& e,
             ::xml_schema::flags f,
             ::xml_schema::container* c)
  : ::xml_schema::type (e, f | ::xml_schema::flags::base, c),
    faction_code_ (this),
    our_mask_ (this),
    friendly_mask_ (this),
    hostile_mask_ (this),
    friendly_factions_ (this),
    hostile_factions_ (this)
  {
    if ((f & ::xml_schema::flags::base) == 0)
    {
      ::xsd::cxx::xml::dom::parser< wchar_t > p (e, false, false, true);
      this->parse (p, f);
    }
  }

  void faction_t::
  parse (::xsd::cxx::xml::dom::parser< wchar_t >& p,
         ::xml_schema::flags f)
  {
    while (p.more_attributes ())
    {
      const ::xercesc::DOMAttr& i (p.next_attribute ());
      const ::xsd::cxx::xml::qualified_name< wchar_t > n (
        ::xsd::cxx::xml::dom::name< wchar_t > (i));

      if (n.name () == L"faction_code" && n.namespace_ ().empty ())
      {
        this->faction_code_.set (faction_code_traits::create (i, f, this));
        continue;
      }

      if (n.name () == L"our_mask" && n.namespace_ ().empty ())
      {
        this->our_mask_.set (our_mask_traits::create (i, f, this));
        continue;
      }

      if (n.name () == L"friendly_mask" && n.namespace_ ().empty ())
      {
        this->friendly_mask_.set (friendly_mask_traits::create (i, f, this));
        continue;
      }

      if (n.name () == L"hostile_mask" && n.namespace_ ().empty ())
      {
        this->hostile_mask_.set (hostile_mask_traits::create (i, f, this));
        continue;
      }

      if (n.name () == L"friendly_factions" && n.namespace_ ().empty ())
      {
        this->friendly_factions_.set (friendly_factions_traits::create (i, f, this));
        continue;
      }

      if (n.name () == L"hostile_factions" && n.namespace_ ().empty ())
      {
        this->hostile_factions_.set (hostile_factions_traits::create (i, f, this));
        continue;
      }
    }

    if (!faction_code_.present ())
    {
      throw ::xsd::cxx::tree::expected_attribute< wchar_t > (
        L"faction_code",
        L"");
    }

    if (!our_mask_.present ())
    {
      throw ::xsd::cxx::tree::expected_attribute< wchar_t > (
        L"our_mask",
        L"");
    }

    if (!friendly_mask_.present ())
    {
      throw ::xsd::cxx::tree::expected_attribute< wchar_t > (
        L"friendly_mask",
        L"");
    }

    if (!hostile_mask_.present ())
    {
      throw ::xsd::cxx::tree::expected_attribute< wchar_t > (
        L"hostile_mask",
        L"");
    }
  }

  faction_t* faction_t::
  _clone (::xml_schema::flags f,
          ::xml_schema::container* c) const
  {
    return new class faction_t (*this, f, c);
  }

  faction_t& faction_t::
  operator= (const faction_t& x)
  {
    if (this != &x)
    {
      static_cast< ::xml_schema::type& > (*this) = x;
      this->faction_code_ = x.faction_code_;
      this->our_mask_ = x.our_mask_;
      this->friendly_mask_ = x.friendly_mask_;
      this->hostile_mask_ = x.hostile_mask_;
      this->friendly_factions_ = x.friendly_factions_;
      this->hostile_factions_ = x.hostile_factions_;
    }

    return *this;
  }

  faction_t::
  ~faction_t ()
  {
  }

  // faction_list_t
  //

  faction_list_t::
  faction_list_t (const ::xercesc::DOMElement& e,
                  ::xml_schema::flags f,
                  ::xml_schema::container* c)
  : ::xml_schema::simple_type (e, f, c),
    ::xsd::cxx::tree::list< ::xml_schema::unsigned_byte, wchar_t > (e, f, this)
  {
  }

  faction_list_t::
  faction_list_t (const ::xercesc::DOMAttr& a,
                  ::xml_schema::flags f,
                  ::xml_schema::container* c)
  : ::xml_schema::simple_type (a, f, c),
    ::xsd::cxx::tree::list< ::xml_schema::unsigned_byte, wchar_t > (a, f, this)
  {
  }

  faction_list_t::
  faction_list_t (const ::std::wstring& s,
                  const ::xercesc::DOMElement* e,
                  ::xml_schema::flags f,
                  ::xml_schema::container* c)
  : ::xml_schema::simple_type (s, e, f, c),
    ::xsd::cxx::tree::list< ::xml_schema::unsigned_byte, wchar_t > (s, e, f, this)
  {
  }

  faction_list_t* faction_list_t::
  _clone (::xml_schema::flags f,
          ::xml_schema::container* c) const
  {
    return new class faction_list_t (*this, f, c);
  }

  faction_list_t::
  ~faction_list_t ()
  {
  }

  // faction_table
  //

  faction_table::
  faction_table ()
  : ::xml_schema::type (),
    faction_template_ (this)
  {
  }

  faction_table::
  faction_table (const faction_table& x,
                 ::xml_schema::flags f,
                 ::xml_schema::container* c)
  : ::xml_schema::type (x, f, c),
    faction_template_ (x.faction_template_, f, this)
  {
  }

  faction_table::
  faction_table (const ::xercesc::DOMElement& e,
                 ::xml_schema::flags f,
                 ::xml_schema::container* c)
  : ::xml_schema::type (e, f | ::xml_schema::flags::base, c),
    faction_template_ (this)
  {
    if ((f & ::xml_schema::flags::base) == 0)
    {
      ::xsd::cxx::xml::dom::parser< wchar_t > p (e, true, false, false);
      this->parse (p, f);
    }
  }

  void faction_table::
  parse (::xsd::cxx::xml::dom::parser< wchar_t >& p,
         ::xml_schema::flags f)
  {
    for (; p.more_content (); p.next_content (false))
    {
      const ::xercesc::DOMElement& i (p.cur_element ());
      const ::xsd::cxx::xml::qualified_name< wchar_t > n (
        ::xsd::cxx::xml::dom::name< wchar_t > (i));

      // faction_template
      //
      if (n.name () == L"faction_template" && n.namespace_ ().empty ())
      {
        ::std::unique_ptr< faction_template_type > r (
          faction_template_traits::create (i, f, this));

        this->faction_template_.push_back (::std::move (r));
        continue;
      }

      break;
    }
  }

  faction_table* faction_table::
  _clone (::xml_schema::flags f,
          ::xml_schema::container* c) const
  {
    return new class faction_table (*this, f, c);
  }

  faction_table& faction_table::
  operator= (const faction_table& x)
  {
    if (this != &x)
    {
      static_cast< ::xml_schema::type& > (*this) = x;
      this->faction_template_ = x.faction_template_;
    }

    return *this;
  }

  faction_table::
  ~faction_table ()
  {
  }
}

#include <istream>
#include <xsd/cxx/xml/sax/std-input-source.hxx>
#include <xsd/cxx/tree/error-handler.hxx>

namespace gdt
{
  ::std::unique_ptr< ::gdt::faction_table >
  faction_table_ (const ::std::wstring& u,
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

    return ::std::unique_ptr< ::gdt::faction_table > (
      ::gdt::faction_table_ (
        std::move (d), f | ::xml_schema::flags::own_dom, p));
  }

  ::std::unique_ptr< ::gdt::faction_table >
  faction_table_ (const ::std::wstring& u,
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

    return ::std::unique_ptr< ::gdt::faction_table > (
      ::gdt::faction_table_ (
        std::move (d), f | ::xml_schema::flags::own_dom, p));
  }

  ::std::unique_ptr< ::gdt::faction_table >
  faction_table_ (const ::std::wstring& u,
                  ::xercesc::DOMErrorHandler& h,
                  ::xml_schema::flags f,
                  const ::xml_schema::properties& p)
  {
    ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
      ::xsd::cxx::xml::dom::parse< wchar_t > (
        u, h, p, f));

    if (!d.get ())
      throw ::xsd::cxx::tree::parsing< wchar_t > ();

    return ::std::unique_ptr< ::gdt::faction_table > (
      ::gdt::faction_table_ (
        std::move (d), f | ::xml_schema::flags::own_dom, p));
  }

  ::std::unique_ptr< ::gdt::faction_table >
  faction_table_ (::std::istream& is,
                  ::xml_schema::flags f,
                  const ::xml_schema::properties& p)
  {
    ::xsd::cxx::xml::auto_initializer i (
      (f & ::xml_schema::flags::dont_initialize) == 0,
      (f & ::xml_schema::flags::keep_dom) == 0);

    ::xsd::cxx::xml::sax::std_input_source isrc (is);
    return ::gdt::faction_table_ (isrc, f, p);
  }

  ::std::unique_ptr< ::gdt::faction_table >
  faction_table_ (::std::istream& is,
                  ::xml_schema::error_handler& h,
                  ::xml_schema::flags f,
                  const ::xml_schema::properties& p)
  {
    ::xsd::cxx::xml::auto_initializer i (
      (f & ::xml_schema::flags::dont_initialize) == 0,
      (f & ::xml_schema::flags::keep_dom) == 0);

    ::xsd::cxx::xml::sax::std_input_source isrc (is);
    return ::gdt::faction_table_ (isrc, h, f, p);
  }

  ::std::unique_ptr< ::gdt::faction_table >
  faction_table_ (::std::istream& is,
                  ::xercesc::DOMErrorHandler& h,
                  ::xml_schema::flags f,
                  const ::xml_schema::properties& p)
  {
    ::xsd::cxx::xml::sax::std_input_source isrc (is);
    return ::gdt::faction_table_ (isrc, h, f, p);
  }

  ::std::unique_ptr< ::gdt::faction_table >
  faction_table_ (::std::istream& is,
                  const ::std::wstring& sid,
                  ::xml_schema::flags f,
                  const ::xml_schema::properties& p)
  {
    ::xsd::cxx::xml::auto_initializer i (
      (f & ::xml_schema::flags::dont_initialize) == 0,
      (f & ::xml_schema::flags::keep_dom) == 0);

    ::xsd::cxx::xml::sax::std_input_source isrc (is, sid);
    return ::gdt::faction_table_ (isrc, f, p);
  }

  ::std::unique_ptr< ::gdt::faction_table >
  faction_table_ (::std::istream& is,
                  const ::std::wstring& sid,
                  ::xml_schema::error_handler& h,
                  ::xml_schema::flags f,
                  const ::xml_schema::properties& p)
  {
    ::xsd::cxx::xml::auto_initializer i (
      (f & ::xml_schema::flags::dont_initialize) == 0,
      (f & ::xml_schema::flags::keep_dom) == 0);

    ::xsd::cxx::xml::sax::std_input_source isrc (is, sid);
    return ::gdt::faction_table_ (isrc, h, f, p);
  }

  ::std::unique_ptr< ::gdt::faction_table >
  faction_table_ (::std::istream& is,
                  const ::std::wstring& sid,
                  ::xercesc::DOMErrorHandler& h,
                  ::xml_schema::flags f,
                  const ::xml_schema::properties& p)
  {
    ::xsd::cxx::xml::sax::std_input_source isrc (is, sid);
    return ::gdt::faction_table_ (isrc, h, f, p);
  }

  ::std::unique_ptr< ::gdt::faction_table >
  faction_table_ (::xercesc::InputSource& i,
                  ::xml_schema::flags f,
                  const ::xml_schema::properties& p)
  {
    ::xsd::cxx::tree::error_handler< wchar_t > h;

    ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
      ::xsd::cxx::xml::dom::parse< wchar_t > (
        i, h, p, f));

    h.throw_if_failed< ::xsd::cxx::tree::parsing< wchar_t > > ();

    return ::std::unique_ptr< ::gdt::faction_table > (
      ::gdt::faction_table_ (
        std::move (d), f | ::xml_schema::flags::own_dom, p));
  }

  ::std::unique_ptr< ::gdt::faction_table >
  faction_table_ (::xercesc::InputSource& i,
                  ::xml_schema::error_handler& h,
                  ::xml_schema::flags f,
                  const ::xml_schema::properties& p)
  {
    ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
      ::xsd::cxx::xml::dom::parse< wchar_t > (
        i, h, p, f));

    if (!d.get ())
      throw ::xsd::cxx::tree::parsing< wchar_t > ();

    return ::std::unique_ptr< ::gdt::faction_table > (
      ::gdt::faction_table_ (
        std::move (d), f | ::xml_schema::flags::own_dom, p));
  }

  ::std::unique_ptr< ::gdt::faction_table >
  faction_table_ (::xercesc::InputSource& i,
                  ::xercesc::DOMErrorHandler& h,
                  ::xml_schema::flags f,
                  const ::xml_schema::properties& p)
  {
    ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
      ::xsd::cxx::xml::dom::parse< wchar_t > (
        i, h, p, f));

    if (!d.get ())
      throw ::xsd::cxx::tree::parsing< wchar_t > ();

    return ::std::unique_ptr< ::gdt::faction_table > (
      ::gdt::faction_table_ (
        std::move (d), f | ::xml_schema::flags::own_dom, p));
  }

  ::std::unique_ptr< ::gdt::faction_table >
  faction_table_ (const ::xercesc::DOMDocument& doc,
                  ::xml_schema::flags f,
                  const ::xml_schema::properties& p)
  {
    if (f & ::xml_schema::flags::keep_dom)
    {
      ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
        static_cast< ::xercesc::DOMDocument* > (doc.cloneNode (true)));

      return ::std::unique_ptr< ::gdt::faction_table > (
        ::gdt::faction_table_ (
          std::move (d), f | ::xml_schema::flags::own_dom, p));
    }

    const ::xercesc::DOMElement& e (*doc.getDocumentElement ());
    const ::xsd::cxx::xml::qualified_name< wchar_t > n (
      ::xsd::cxx::xml::dom::name< wchar_t > (e));

    if (n.name () == L"faction_table" &&
        n.namespace_ () == L"")
    {
      ::std::unique_ptr< ::gdt::faction_table > r (
        ::xsd::cxx::tree::traits< ::gdt::faction_table, wchar_t >::create (
          e, f, 0));
      return r;
    }

    throw ::xsd::cxx::tree::unexpected_element < wchar_t > (
      n.name (),
      n.namespace_ (),
      L"faction_table",
      L"");
  }

  ::std::unique_ptr< ::gdt::faction_table >
  faction_table_ (::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d,
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

    if (n.name () == L"faction_table" &&
        n.namespace_ () == L"")
    {
      ::std::unique_ptr< ::gdt::faction_table > r (
        ::xsd::cxx::tree::traits< ::gdt::faction_table, wchar_t >::create (
          e, f, 0));
      return r;
    }

    throw ::xsd::cxx::tree::unexpected_element < wchar_t > (
      n.name (),
      n.namespace_ (),
      L"faction_table",
      L"");
  }
}

#include <ostream>
#include <xsd/cxx/tree/error-handler.hxx>
#include <xsd/cxx/xml/dom/serialization-source.hxx>

namespace gdt
{
  void
  faction_table_ (::std::ostream& o,
                  const ::gdt::faction_table& s,
                  const ::xml_schema::namespace_infomap& m,
                  const ::std::wstring& e,
                  ::xml_schema::flags f)
  {
    ::xsd::cxx::xml::auto_initializer i (
      (f & ::xml_schema::flags::dont_initialize) == 0);

    ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
      ::gdt::faction_table_ (s, m, f));

    ::xsd::cxx::tree::error_handler< wchar_t > h;

    ::xsd::cxx::xml::dom::ostream_format_target t (o);
    if (!::xsd::cxx::xml::dom::serialize (t, *d, e, h, f))
    {
      h.throw_if_failed< ::xsd::cxx::tree::serialization< wchar_t > > ();
    }
  }

  void
  faction_table_ (::std::ostream& o,
                  const ::gdt::faction_table& s,
                  ::xml_schema::error_handler& h,
                  const ::xml_schema::namespace_infomap& m,
                  const ::std::wstring& e,
                  ::xml_schema::flags f)
  {
    ::xsd::cxx::xml::auto_initializer i (
      (f & ::xml_schema::flags::dont_initialize) == 0);

    ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
      ::gdt::faction_table_ (s, m, f));
    ::xsd::cxx::xml::dom::ostream_format_target t (o);
    if (!::xsd::cxx::xml::dom::serialize (t, *d, e, h, f))
    {
      throw ::xsd::cxx::tree::serialization< wchar_t > ();
    }
  }

  void
  faction_table_ (::std::ostream& o,
                  const ::gdt::faction_table& s,
                  ::xercesc::DOMErrorHandler& h,
                  const ::xml_schema::namespace_infomap& m,
                  const ::std::wstring& e,
                  ::xml_schema::flags f)
  {
    ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
      ::gdt::faction_table_ (s, m, f));
    ::xsd::cxx::xml::dom::ostream_format_target t (o);
    if (!::xsd::cxx::xml::dom::serialize (t, *d, e, h, f))
    {
      throw ::xsd::cxx::tree::serialization< wchar_t > ();
    }
  }

  void
  faction_table_ (::xercesc::XMLFormatTarget& t,
                  const ::gdt::faction_table& s,
                  const ::xml_schema::namespace_infomap& m,
                  const ::std::wstring& e,
                  ::xml_schema::flags f)
  {
    ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
      ::gdt::faction_table_ (s, m, f));

    ::xsd::cxx::tree::error_handler< wchar_t > h;

    if (!::xsd::cxx::xml::dom::serialize (t, *d, e, h, f))
    {
      h.throw_if_failed< ::xsd::cxx::tree::serialization< wchar_t > > ();
    }
  }

  void
  faction_table_ (::xercesc::XMLFormatTarget& t,
                  const ::gdt::faction_table& s,
                  ::xml_schema::error_handler& h,
                  const ::xml_schema::namespace_infomap& m,
                  const ::std::wstring& e,
                  ::xml_schema::flags f)
  {
    ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
      ::gdt::faction_table_ (s, m, f));
    if (!::xsd::cxx::xml::dom::serialize (t, *d, e, h, f))
    {
      throw ::xsd::cxx::tree::serialization< wchar_t > ();
    }
  }

  void
  faction_table_ (::xercesc::XMLFormatTarget& t,
                  const ::gdt::faction_table& s,
                  ::xercesc::DOMErrorHandler& h,
                  const ::xml_schema::namespace_infomap& m,
                  const ::std::wstring& e,
                  ::xml_schema::flags f)
  {
    ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
      ::gdt::faction_table_ (s, m, f));
    if (!::xsd::cxx::xml::dom::serialize (t, *d, e, h, f))
    {
      throw ::xsd::cxx::tree::serialization< wchar_t > ();
    }
  }

  void
  faction_table_ (::xercesc::DOMDocument& d,
                  const ::gdt::faction_table& s,
                  ::xml_schema::flags)
  {
    ::xercesc::DOMElement& e (*d.getDocumentElement ());
    const ::xsd::cxx::xml::qualified_name< wchar_t > n (
      ::xsd::cxx::xml::dom::name< wchar_t > (e));

    if (n.name () == L"faction_table" &&
        n.namespace_ () == L"")
    {
      e << s;
    }
    else
    {
      throw ::xsd::cxx::tree::unexpected_element < wchar_t > (
        n.name (),
        n.namespace_ (),
        L"faction_table",
        L"");
    }
  }

  ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument >
  faction_table_ (const ::gdt::faction_table& s,
                  const ::xml_schema::namespace_infomap& m,
                  ::xml_schema::flags f)
  {
    ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
      ::xsd::cxx::xml::dom::serialize< wchar_t > (
        L"faction_table",
        L"",
        m, f));

    ::gdt::faction_table_ (*d, s, f);
    return d;
  }

  void
  operator<< (::xercesc::DOMElement& e, const faction_t& i)
  {
    e << static_cast< const ::xml_schema::type& > (i);

    // faction_code
    //
    {
      ::xercesc::DOMAttr& a (
        ::xsd::cxx::xml::dom::create_attribute (
          L"faction_code",
          e));

      a << i.faction_code ();
    }

    // our_mask
    //
    {
      ::xercesc::DOMAttr& a (
        ::xsd::cxx::xml::dom::create_attribute (
          L"our_mask",
          e));

      a << i.our_mask ();
    }

    // friendly_mask
    //
    {
      ::xercesc::DOMAttr& a (
        ::xsd::cxx::xml::dom::create_attribute (
          L"friendly_mask",
          e));

      a << i.friendly_mask ();
    }

    // hostile_mask
    //
    {
      ::xercesc::DOMAttr& a (
        ::xsd::cxx::xml::dom::create_attribute (
          L"hostile_mask",
          e));

      a << i.hostile_mask ();
    }

    // friendly_factions
    //
    if (i.friendly_factions ())
    {
      ::xercesc::DOMAttr& a (
        ::xsd::cxx::xml::dom::create_attribute (
          L"friendly_factions",
          e));

      a << *i.friendly_factions ();
    }

    // hostile_factions
    //
    if (i.hostile_factions ())
    {
      ::xercesc::DOMAttr& a (
        ::xsd::cxx::xml::dom::create_attribute (
          L"hostile_factions",
          e));

      a << *i.hostile_factions ();
    }
  }

  void
  operator<< (::xercesc::DOMElement& e, const faction_list_t& i)
  {
    e << static_cast< const ::xsd::cxx::tree::list< ::xml_schema::unsigned_byte, wchar_t >& > (i);
  }

  void
  operator<< (::xercesc::DOMAttr& a, const faction_list_t& i)
  {
    a << static_cast< const ::xsd::cxx::tree::list< ::xml_schema::unsigned_byte, wchar_t >& > (i);
  }

  void
  operator<< (::xml_schema::list_stream& l,
              const faction_list_t& i)
  {
    l << static_cast< const ::xsd::cxx::tree::list< ::xml_schema::unsigned_byte, wchar_t >& > (i);
  }

  void
  operator<< (::xercesc::DOMElement& e, const faction_table& i)
  {
    e << static_cast< const ::xml_schema::type& > (i);

    // faction_template
    //
    for (faction_table::faction_template_const_iterator
         b (i.faction_template ().begin ()), n (i.faction_template ().end ());
         b != n; ++b)
    {
      ::xercesc::DOMElement& s (
        ::xsd::cxx::xml::dom::create_element (
          L"faction_template",
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

