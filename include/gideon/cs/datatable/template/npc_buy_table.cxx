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

#include "npc_buy_table.hxx"

#include <xsd/cxx/xml/dom/parsing-source.hxx>

namespace gdt
{
  // npc_buy_t
  //

  npc_buy_t::
  npc_buy_t ()
  : ::xml_schema::type (),
    npc_code_ (this),
    item_code_type_ (this)
  {
  }

  npc_buy_t::
  npc_buy_t (const npc_code_type& npc_code,
             const item_code_type_type& item_code_type)
  : ::xml_schema::type (),
    npc_code_ (npc_code, this),
    item_code_type_ (item_code_type, this)
  {
  }

  npc_buy_t::
  npc_buy_t (const npc_buy_t& x,
             ::xml_schema::flags f,
             ::xml_schema::container* c)
  : ::xml_schema::type (x, f, c),
    npc_code_ (x.npc_code_, f, this),
    item_code_type_ (x.item_code_type_, f, this)
  {
  }

  npc_buy_t::
  npc_buy_t (const ::xercesc::DOMElement& e,
             ::xml_schema::flags f,
             ::xml_schema::container* c)
  : ::xml_schema::type (e, f | ::xml_schema::flags::base, c),
    npc_code_ (this),
    item_code_type_ (this)
  {
    if ((f & ::xml_schema::flags::base) == 0)
    {
      ::xsd::cxx::xml::dom::parser< wchar_t > p (e, false, false, true);
      this->parse (p, f);
    }
  }

  void npc_buy_t::
  parse (::xsd::cxx::xml::dom::parser< wchar_t >& p,
         ::xml_schema::flags f)
  {
    while (p.more_attributes ())
    {
      const ::xercesc::DOMAttr& i (p.next_attribute ());
      const ::xsd::cxx::xml::qualified_name< wchar_t > n (
        ::xsd::cxx::xml::dom::name< wchar_t > (i));

      if (n.name () == L"npc_code" && n.namespace_ ().empty ())
      {
        this->npc_code_.set (npc_code_traits::create (i, f, this));
        continue;
      }

      if (n.name () == L"item_code_type" && n.namespace_ ().empty ())
      {
        this->item_code_type_.set (item_code_type_traits::create (i, f, this));
        continue;
      }
    }

    if (!npc_code_.present ())
    {
      throw ::xsd::cxx::tree::expected_attribute< wchar_t > (
        L"npc_code",
        L"");
    }

    if (!item_code_type_.present ())
    {
      throw ::xsd::cxx::tree::expected_attribute< wchar_t > (
        L"item_code_type",
        L"");
    }
  }

  npc_buy_t* npc_buy_t::
  _clone (::xml_schema::flags f,
          ::xml_schema::container* c) const
  {
    return new class npc_buy_t (*this, f, c);
  }

  npc_buy_t& npc_buy_t::
  operator= (const npc_buy_t& x)
  {
    if (this != &x)
    {
      static_cast< ::xml_schema::type& > (*this) = x;
      this->npc_code_ = x.npc_code_;
      this->item_code_type_ = x.item_code_type_;
    }

    return *this;
  }

  npc_buy_t::
  ~npc_buy_t ()
  {
  }

  // npc_buy_table
  //

  npc_buy_table::
  npc_buy_table ()
  : ::xml_schema::type (),
    npc_buy_template_ (this)
  {
  }

  npc_buy_table::
  npc_buy_table (const npc_buy_table& x,
                 ::xml_schema::flags f,
                 ::xml_schema::container* c)
  : ::xml_schema::type (x, f, c),
    npc_buy_template_ (x.npc_buy_template_, f, this)
  {
  }

  npc_buy_table::
  npc_buy_table (const ::xercesc::DOMElement& e,
                 ::xml_schema::flags f,
                 ::xml_schema::container* c)
  : ::xml_schema::type (e, f | ::xml_schema::flags::base, c),
    npc_buy_template_ (this)
  {
    if ((f & ::xml_schema::flags::base) == 0)
    {
      ::xsd::cxx::xml::dom::parser< wchar_t > p (e, true, false, false);
      this->parse (p, f);
    }
  }

  void npc_buy_table::
  parse (::xsd::cxx::xml::dom::parser< wchar_t >& p,
         ::xml_schema::flags f)
  {
    for (; p.more_content (); p.next_content (false))
    {
      const ::xercesc::DOMElement& i (p.cur_element ());
      const ::xsd::cxx::xml::qualified_name< wchar_t > n (
        ::xsd::cxx::xml::dom::name< wchar_t > (i));

      // npc_buy_template
      //
      if (n.name () == L"npc_buy_template" && n.namespace_ ().empty ())
      {
        ::std::unique_ptr< npc_buy_template_type > r (
          npc_buy_template_traits::create (i, f, this));

        this->npc_buy_template_.push_back (::std::move (r));
        continue;
      }

      break;
    }
  }

  npc_buy_table* npc_buy_table::
  _clone (::xml_schema::flags f,
          ::xml_schema::container* c) const
  {
    return new class npc_buy_table (*this, f, c);
  }

  npc_buy_table& npc_buy_table::
  operator= (const npc_buy_table& x)
  {
    if (this != &x)
    {
      static_cast< ::xml_schema::type& > (*this) = x;
      this->npc_buy_template_ = x.npc_buy_template_;
    }

    return *this;
  }

  npc_buy_table::
  ~npc_buy_table ()
  {
  }
}

#include <istream>
#include <xsd/cxx/xml/sax/std-input-source.hxx>
#include <xsd/cxx/tree/error-handler.hxx>

namespace gdt
{
  ::std::unique_ptr< ::gdt::npc_buy_table >
  npc_buy_table_ (const ::std::wstring& u,
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

    return ::std::unique_ptr< ::gdt::npc_buy_table > (
      ::gdt::npc_buy_table_ (
        std::move (d), f | ::xml_schema::flags::own_dom, p));
  }

  ::std::unique_ptr< ::gdt::npc_buy_table >
  npc_buy_table_ (const ::std::wstring& u,
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

    return ::std::unique_ptr< ::gdt::npc_buy_table > (
      ::gdt::npc_buy_table_ (
        std::move (d), f | ::xml_schema::flags::own_dom, p));
  }

  ::std::unique_ptr< ::gdt::npc_buy_table >
  npc_buy_table_ (const ::std::wstring& u,
                  ::xercesc::DOMErrorHandler& h,
                  ::xml_schema::flags f,
                  const ::xml_schema::properties& p)
  {
    ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
      ::xsd::cxx::xml::dom::parse< wchar_t > (
        u, h, p, f));

    if (!d.get ())
      throw ::xsd::cxx::tree::parsing< wchar_t > ();

    return ::std::unique_ptr< ::gdt::npc_buy_table > (
      ::gdt::npc_buy_table_ (
        std::move (d), f | ::xml_schema::flags::own_dom, p));
  }

  ::std::unique_ptr< ::gdt::npc_buy_table >
  npc_buy_table_ (::std::istream& is,
                  ::xml_schema::flags f,
                  const ::xml_schema::properties& p)
  {
    ::xsd::cxx::xml::auto_initializer i (
      (f & ::xml_schema::flags::dont_initialize) == 0,
      (f & ::xml_schema::flags::keep_dom) == 0);

    ::xsd::cxx::xml::sax::std_input_source isrc (is);
    return ::gdt::npc_buy_table_ (isrc, f, p);
  }

  ::std::unique_ptr< ::gdt::npc_buy_table >
  npc_buy_table_ (::std::istream& is,
                  ::xml_schema::error_handler& h,
                  ::xml_schema::flags f,
                  const ::xml_schema::properties& p)
  {
    ::xsd::cxx::xml::auto_initializer i (
      (f & ::xml_schema::flags::dont_initialize) == 0,
      (f & ::xml_schema::flags::keep_dom) == 0);

    ::xsd::cxx::xml::sax::std_input_source isrc (is);
    return ::gdt::npc_buy_table_ (isrc, h, f, p);
  }

  ::std::unique_ptr< ::gdt::npc_buy_table >
  npc_buy_table_ (::std::istream& is,
                  ::xercesc::DOMErrorHandler& h,
                  ::xml_schema::flags f,
                  const ::xml_schema::properties& p)
  {
    ::xsd::cxx::xml::sax::std_input_source isrc (is);
    return ::gdt::npc_buy_table_ (isrc, h, f, p);
  }

  ::std::unique_ptr< ::gdt::npc_buy_table >
  npc_buy_table_ (::std::istream& is,
                  const ::std::wstring& sid,
                  ::xml_schema::flags f,
                  const ::xml_schema::properties& p)
  {
    ::xsd::cxx::xml::auto_initializer i (
      (f & ::xml_schema::flags::dont_initialize) == 0,
      (f & ::xml_schema::flags::keep_dom) == 0);

    ::xsd::cxx::xml::sax::std_input_source isrc (is, sid);
    return ::gdt::npc_buy_table_ (isrc, f, p);
  }

  ::std::unique_ptr< ::gdt::npc_buy_table >
  npc_buy_table_ (::std::istream& is,
                  const ::std::wstring& sid,
                  ::xml_schema::error_handler& h,
                  ::xml_schema::flags f,
                  const ::xml_schema::properties& p)
  {
    ::xsd::cxx::xml::auto_initializer i (
      (f & ::xml_schema::flags::dont_initialize) == 0,
      (f & ::xml_schema::flags::keep_dom) == 0);

    ::xsd::cxx::xml::sax::std_input_source isrc (is, sid);
    return ::gdt::npc_buy_table_ (isrc, h, f, p);
  }

  ::std::unique_ptr< ::gdt::npc_buy_table >
  npc_buy_table_ (::std::istream& is,
                  const ::std::wstring& sid,
                  ::xercesc::DOMErrorHandler& h,
                  ::xml_schema::flags f,
                  const ::xml_schema::properties& p)
  {
    ::xsd::cxx::xml::sax::std_input_source isrc (is, sid);
    return ::gdt::npc_buy_table_ (isrc, h, f, p);
  }

  ::std::unique_ptr< ::gdt::npc_buy_table >
  npc_buy_table_ (::xercesc::InputSource& i,
                  ::xml_schema::flags f,
                  const ::xml_schema::properties& p)
  {
    ::xsd::cxx::tree::error_handler< wchar_t > h;

    ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
      ::xsd::cxx::xml::dom::parse< wchar_t > (
        i, h, p, f));

    h.throw_if_failed< ::xsd::cxx::tree::parsing< wchar_t > > ();

    return ::std::unique_ptr< ::gdt::npc_buy_table > (
      ::gdt::npc_buy_table_ (
        std::move (d), f | ::xml_schema::flags::own_dom, p));
  }

  ::std::unique_ptr< ::gdt::npc_buy_table >
  npc_buy_table_ (::xercesc::InputSource& i,
                  ::xml_schema::error_handler& h,
                  ::xml_schema::flags f,
                  const ::xml_schema::properties& p)
  {
    ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
      ::xsd::cxx::xml::dom::parse< wchar_t > (
        i, h, p, f));

    if (!d.get ())
      throw ::xsd::cxx::tree::parsing< wchar_t > ();

    return ::std::unique_ptr< ::gdt::npc_buy_table > (
      ::gdt::npc_buy_table_ (
        std::move (d), f | ::xml_schema::flags::own_dom, p));
  }

  ::std::unique_ptr< ::gdt::npc_buy_table >
  npc_buy_table_ (::xercesc::InputSource& i,
                  ::xercesc::DOMErrorHandler& h,
                  ::xml_schema::flags f,
                  const ::xml_schema::properties& p)
  {
    ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
      ::xsd::cxx::xml::dom::parse< wchar_t > (
        i, h, p, f));

    if (!d.get ())
      throw ::xsd::cxx::tree::parsing< wchar_t > ();

    return ::std::unique_ptr< ::gdt::npc_buy_table > (
      ::gdt::npc_buy_table_ (
        std::move (d), f | ::xml_schema::flags::own_dom, p));
  }

  ::std::unique_ptr< ::gdt::npc_buy_table >
  npc_buy_table_ (const ::xercesc::DOMDocument& doc,
                  ::xml_schema::flags f,
                  const ::xml_schema::properties& p)
  {
    if (f & ::xml_schema::flags::keep_dom)
    {
      ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
        static_cast< ::xercesc::DOMDocument* > (doc.cloneNode (true)));

      return ::std::unique_ptr< ::gdt::npc_buy_table > (
        ::gdt::npc_buy_table_ (
          std::move (d), f | ::xml_schema::flags::own_dom, p));
    }

    const ::xercesc::DOMElement& e (*doc.getDocumentElement ());
    const ::xsd::cxx::xml::qualified_name< wchar_t > n (
      ::xsd::cxx::xml::dom::name< wchar_t > (e));

    if (n.name () == L"npc_buy_table" &&
        n.namespace_ () == L"")
    {
      ::std::unique_ptr< ::gdt::npc_buy_table > r (
        ::xsd::cxx::tree::traits< ::gdt::npc_buy_table, wchar_t >::create (
          e, f, 0));
      return r;
    }

    throw ::xsd::cxx::tree::unexpected_element < wchar_t > (
      n.name (),
      n.namespace_ (),
      L"npc_buy_table",
      L"");
  }

  ::std::unique_ptr< ::gdt::npc_buy_table >
  npc_buy_table_ (::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d,
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

    if (n.name () == L"npc_buy_table" &&
        n.namespace_ () == L"")
    {
      ::std::unique_ptr< ::gdt::npc_buy_table > r (
        ::xsd::cxx::tree::traits< ::gdt::npc_buy_table, wchar_t >::create (
          e, f, 0));
      return r;
    }

    throw ::xsd::cxx::tree::unexpected_element < wchar_t > (
      n.name (),
      n.namespace_ (),
      L"npc_buy_table",
      L"");
  }
}

#include <ostream>
#include <xsd/cxx/tree/error-handler.hxx>
#include <xsd/cxx/xml/dom/serialization-source.hxx>

namespace gdt
{
  void
  npc_buy_table_ (::std::ostream& o,
                  const ::gdt::npc_buy_table& s,
                  const ::xml_schema::namespace_infomap& m,
                  const ::std::wstring& e,
                  ::xml_schema::flags f)
  {
    ::xsd::cxx::xml::auto_initializer i (
      (f & ::xml_schema::flags::dont_initialize) == 0);

    ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
      ::gdt::npc_buy_table_ (s, m, f));

    ::xsd::cxx::tree::error_handler< wchar_t > h;

    ::xsd::cxx::xml::dom::ostream_format_target t (o);
    if (!::xsd::cxx::xml::dom::serialize (t, *d, e, h, f))
    {
      h.throw_if_failed< ::xsd::cxx::tree::serialization< wchar_t > > ();
    }
  }

  void
  npc_buy_table_ (::std::ostream& o,
                  const ::gdt::npc_buy_table& s,
                  ::xml_schema::error_handler& h,
                  const ::xml_schema::namespace_infomap& m,
                  const ::std::wstring& e,
                  ::xml_schema::flags f)
  {
    ::xsd::cxx::xml::auto_initializer i (
      (f & ::xml_schema::flags::dont_initialize) == 0);

    ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
      ::gdt::npc_buy_table_ (s, m, f));
    ::xsd::cxx::xml::dom::ostream_format_target t (o);
    if (!::xsd::cxx::xml::dom::serialize (t, *d, e, h, f))
    {
      throw ::xsd::cxx::tree::serialization< wchar_t > ();
    }
  }

  void
  npc_buy_table_ (::std::ostream& o,
                  const ::gdt::npc_buy_table& s,
                  ::xercesc::DOMErrorHandler& h,
                  const ::xml_schema::namespace_infomap& m,
                  const ::std::wstring& e,
                  ::xml_schema::flags f)
  {
    ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
      ::gdt::npc_buy_table_ (s, m, f));
    ::xsd::cxx::xml::dom::ostream_format_target t (o);
    if (!::xsd::cxx::xml::dom::serialize (t, *d, e, h, f))
    {
      throw ::xsd::cxx::tree::serialization< wchar_t > ();
    }
  }

  void
  npc_buy_table_ (::xercesc::XMLFormatTarget& t,
                  const ::gdt::npc_buy_table& s,
                  const ::xml_schema::namespace_infomap& m,
                  const ::std::wstring& e,
                  ::xml_schema::flags f)
  {
    ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
      ::gdt::npc_buy_table_ (s, m, f));

    ::xsd::cxx::tree::error_handler< wchar_t > h;

    if (!::xsd::cxx::xml::dom::serialize (t, *d, e, h, f))
    {
      h.throw_if_failed< ::xsd::cxx::tree::serialization< wchar_t > > ();
    }
  }

  void
  npc_buy_table_ (::xercesc::XMLFormatTarget& t,
                  const ::gdt::npc_buy_table& s,
                  ::xml_schema::error_handler& h,
                  const ::xml_schema::namespace_infomap& m,
                  const ::std::wstring& e,
                  ::xml_schema::flags f)
  {
    ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
      ::gdt::npc_buy_table_ (s, m, f));
    if (!::xsd::cxx::xml::dom::serialize (t, *d, e, h, f))
    {
      throw ::xsd::cxx::tree::serialization< wchar_t > ();
    }
  }

  void
  npc_buy_table_ (::xercesc::XMLFormatTarget& t,
                  const ::gdt::npc_buy_table& s,
                  ::xercesc::DOMErrorHandler& h,
                  const ::xml_schema::namespace_infomap& m,
                  const ::std::wstring& e,
                  ::xml_schema::flags f)
  {
    ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
      ::gdt::npc_buy_table_ (s, m, f));
    if (!::xsd::cxx::xml::dom::serialize (t, *d, e, h, f))
    {
      throw ::xsd::cxx::tree::serialization< wchar_t > ();
    }
  }

  void
  npc_buy_table_ (::xercesc::DOMDocument& d,
                  const ::gdt::npc_buy_table& s,
                  ::xml_schema::flags)
  {
    ::xercesc::DOMElement& e (*d.getDocumentElement ());
    const ::xsd::cxx::xml::qualified_name< wchar_t > n (
      ::xsd::cxx::xml::dom::name< wchar_t > (e));

    if (n.name () == L"npc_buy_table" &&
        n.namespace_ () == L"")
    {
      e << s;
    }
    else
    {
      throw ::xsd::cxx::tree::unexpected_element < wchar_t > (
        n.name (),
        n.namespace_ (),
        L"npc_buy_table",
        L"");
    }
  }

  ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument >
  npc_buy_table_ (const ::gdt::npc_buy_table& s,
                  const ::xml_schema::namespace_infomap& m,
                  ::xml_schema::flags f)
  {
    ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
      ::xsd::cxx::xml::dom::serialize< wchar_t > (
        L"npc_buy_table",
        L"",
        m, f));

    ::gdt::npc_buy_table_ (*d, s, f);
    return d;
  }

  void
  operator<< (::xercesc::DOMElement& e, const npc_buy_t& i)
  {
    e << static_cast< const ::xml_schema::type& > (i);

    // npc_code
    //
    {
      ::xercesc::DOMAttr& a (
        ::xsd::cxx::xml::dom::create_attribute (
          L"npc_code",
          e));

      a << i.npc_code ();
    }

    // item_code_type
    //
    {
      ::xercesc::DOMAttr& a (
        ::xsd::cxx::xml::dom::create_attribute (
          L"item_code_type",
          e));

      a << i.item_code_type ();
    }
  }

  void
  operator<< (::xercesc::DOMElement& e, const npc_buy_table& i)
  {
    e << static_cast< const ::xml_schema::type& > (i);

    // npc_buy_template
    //
    for (npc_buy_table::npc_buy_template_const_iterator
         b (i.npc_buy_template ().begin ()), n (i.npc_buy_template ().end ());
         b != n; ++b)
    {
      ::xercesc::DOMElement& s (
        ::xsd::cxx::xml::dom::create_element (
          L"npc_buy_template",
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

