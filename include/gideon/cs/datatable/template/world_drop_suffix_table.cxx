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

#include "world_drop_suffix_table.hxx"

#include <xsd/cxx/xml/dom/parsing-source.hxx>

namespace gdt
{
  // world_drop_suffix_t
  //

  world_drop_suffix_t::
  world_drop_suffix_t ()
  : ::xml_schema::type (),
    index_ (this),
    world_drop_id_1_ (this),
    world_drop_id_2_ (this),
    world_drop_id_3_ (this),
    world_drop_id_4_ (this),
    world_drop_id_5_ (this),
    loop_count_ (this),
    drop_pct_ (this)
  {
  }

  world_drop_suffix_t::
  world_drop_suffix_t (const index_type& index,
                       const world_drop_id_1_type& world_drop_id_1,
                       const world_drop_id_2_type& world_drop_id_2,
                       const world_drop_id_3_type& world_drop_id_3,
                       const world_drop_id_4_type& world_drop_id_4,
                       const world_drop_id_5_type& world_drop_id_5,
                       const loop_count_type& loop_count,
                       const drop_pct_type& drop_pct)
  : ::xml_schema::type (),
    index_ (index, this),
    world_drop_id_1_ (world_drop_id_1, this),
    world_drop_id_2_ (world_drop_id_2, this),
    world_drop_id_3_ (world_drop_id_3, this),
    world_drop_id_4_ (world_drop_id_4, this),
    world_drop_id_5_ (world_drop_id_5, this),
    loop_count_ (loop_count, this),
    drop_pct_ (drop_pct, this)
  {
  }

  world_drop_suffix_t::
  world_drop_suffix_t (const world_drop_suffix_t& x,
                       ::xml_schema::flags f,
                       ::xml_schema::container* c)
  : ::xml_schema::type (x, f, c),
    index_ (x.index_, f, this),
    world_drop_id_1_ (x.world_drop_id_1_, f, this),
    world_drop_id_2_ (x.world_drop_id_2_, f, this),
    world_drop_id_3_ (x.world_drop_id_3_, f, this),
    world_drop_id_4_ (x.world_drop_id_4_, f, this),
    world_drop_id_5_ (x.world_drop_id_5_, f, this),
    loop_count_ (x.loop_count_, f, this),
    drop_pct_ (x.drop_pct_, f, this)
  {
  }

  world_drop_suffix_t::
  world_drop_suffix_t (const ::xercesc::DOMElement& e,
                       ::xml_schema::flags f,
                       ::xml_schema::container* c)
  : ::xml_schema::type (e, f | ::xml_schema::flags::base, c),
    index_ (this),
    world_drop_id_1_ (this),
    world_drop_id_2_ (this),
    world_drop_id_3_ (this),
    world_drop_id_4_ (this),
    world_drop_id_5_ (this),
    loop_count_ (this),
    drop_pct_ (this)
  {
    if ((f & ::xml_schema::flags::base) == 0)
    {
      ::xsd::cxx::xml::dom::parser< wchar_t > p (e, false, false, true);
      this->parse (p, f);
    }
  }

  void world_drop_suffix_t::
  parse (::xsd::cxx::xml::dom::parser< wchar_t >& p,
         ::xml_schema::flags f)
  {
    while (p.more_attributes ())
    {
      const ::xercesc::DOMAttr& i (p.next_attribute ());
      const ::xsd::cxx::xml::qualified_name< wchar_t > n (
        ::xsd::cxx::xml::dom::name< wchar_t > (i));

      if (n.name () == L"index" && n.namespace_ ().empty ())
      {
        this->index_.set (index_traits::create (i, f, this));
        continue;
      }

      if (n.name () == L"world_drop_id_1" && n.namespace_ ().empty ())
      {
        this->world_drop_id_1_.set (world_drop_id_1_traits::create (i, f, this));
        continue;
      }

      if (n.name () == L"world_drop_id_2" && n.namespace_ ().empty ())
      {
        this->world_drop_id_2_.set (world_drop_id_2_traits::create (i, f, this));
        continue;
      }

      if (n.name () == L"world_drop_id_3" && n.namespace_ ().empty ())
      {
        this->world_drop_id_3_.set (world_drop_id_3_traits::create (i, f, this));
        continue;
      }

      if (n.name () == L"world_drop_id_4" && n.namespace_ ().empty ())
      {
        this->world_drop_id_4_.set (world_drop_id_4_traits::create (i, f, this));
        continue;
      }

      if (n.name () == L"world_drop_id_5" && n.namespace_ ().empty ())
      {
        this->world_drop_id_5_.set (world_drop_id_5_traits::create (i, f, this));
        continue;
      }

      if (n.name () == L"loop_count" && n.namespace_ ().empty ())
      {
        this->loop_count_.set (loop_count_traits::create (i, f, this));
        continue;
      }

      if (n.name () == L"drop_pct" && n.namespace_ ().empty ())
      {
        this->drop_pct_.set (drop_pct_traits::create (i, f, this));
        continue;
      }
    }

    if (!index_.present ())
    {
      throw ::xsd::cxx::tree::expected_attribute< wchar_t > (
        L"index",
        L"");
    }

    if (!world_drop_id_1_.present ())
    {
      throw ::xsd::cxx::tree::expected_attribute< wchar_t > (
        L"world_drop_id_1",
        L"");
    }

    if (!world_drop_id_2_.present ())
    {
      throw ::xsd::cxx::tree::expected_attribute< wchar_t > (
        L"world_drop_id_2",
        L"");
    }

    if (!world_drop_id_3_.present ())
    {
      throw ::xsd::cxx::tree::expected_attribute< wchar_t > (
        L"world_drop_id_3",
        L"");
    }

    if (!world_drop_id_4_.present ())
    {
      throw ::xsd::cxx::tree::expected_attribute< wchar_t > (
        L"world_drop_id_4",
        L"");
    }

    if (!world_drop_id_5_.present ())
    {
      throw ::xsd::cxx::tree::expected_attribute< wchar_t > (
        L"world_drop_id_5",
        L"");
    }

    if (!loop_count_.present ())
    {
      throw ::xsd::cxx::tree::expected_attribute< wchar_t > (
        L"loop_count",
        L"");
    }

    if (!drop_pct_.present ())
    {
      throw ::xsd::cxx::tree::expected_attribute< wchar_t > (
        L"drop_pct",
        L"");
    }
  }

  world_drop_suffix_t* world_drop_suffix_t::
  _clone (::xml_schema::flags f,
          ::xml_schema::container* c) const
  {
    return new class world_drop_suffix_t (*this, f, c);
  }

  world_drop_suffix_t& world_drop_suffix_t::
  operator= (const world_drop_suffix_t& x)
  {
    if (this != &x)
    {
      static_cast< ::xml_schema::type& > (*this) = x;
      this->index_ = x.index_;
      this->world_drop_id_1_ = x.world_drop_id_1_;
      this->world_drop_id_2_ = x.world_drop_id_2_;
      this->world_drop_id_3_ = x.world_drop_id_3_;
      this->world_drop_id_4_ = x.world_drop_id_4_;
      this->world_drop_id_5_ = x.world_drop_id_5_;
      this->loop_count_ = x.loop_count_;
      this->drop_pct_ = x.drop_pct_;
    }

    return *this;
  }

  world_drop_suffix_t::
  ~world_drop_suffix_t ()
  {
  }

  // world_drop_suffix_table
  //

  world_drop_suffix_table::
  world_drop_suffix_table ()
  : ::xml_schema::type (),
    world_drop_suffix_template_ (this)
  {
  }

  world_drop_suffix_table::
  world_drop_suffix_table (const world_drop_suffix_table& x,
                           ::xml_schema::flags f,
                           ::xml_schema::container* c)
  : ::xml_schema::type (x, f, c),
    world_drop_suffix_template_ (x.world_drop_suffix_template_, f, this)
  {
  }

  world_drop_suffix_table::
  world_drop_suffix_table (const ::xercesc::DOMElement& e,
                           ::xml_schema::flags f,
                           ::xml_schema::container* c)
  : ::xml_schema::type (e, f | ::xml_schema::flags::base, c),
    world_drop_suffix_template_ (this)
  {
    if ((f & ::xml_schema::flags::base) == 0)
    {
      ::xsd::cxx::xml::dom::parser< wchar_t > p (e, true, false, false);
      this->parse (p, f);
    }
  }

  void world_drop_suffix_table::
  parse (::xsd::cxx::xml::dom::parser< wchar_t >& p,
         ::xml_schema::flags f)
  {
    for (; p.more_content (); p.next_content (false))
    {
      const ::xercesc::DOMElement& i (p.cur_element ());
      const ::xsd::cxx::xml::qualified_name< wchar_t > n (
        ::xsd::cxx::xml::dom::name< wchar_t > (i));

      // world_drop_suffix_template
      //
      if (n.name () == L"world_drop_suffix_template" && n.namespace_ ().empty ())
      {
        ::std::unique_ptr< world_drop_suffix_template_type > r (
          world_drop_suffix_template_traits::create (i, f, this));

        this->world_drop_suffix_template_.push_back (::std::move (r));
        continue;
      }

      break;
    }
  }

  world_drop_suffix_table* world_drop_suffix_table::
  _clone (::xml_schema::flags f,
          ::xml_schema::container* c) const
  {
    return new class world_drop_suffix_table (*this, f, c);
  }

  world_drop_suffix_table& world_drop_suffix_table::
  operator= (const world_drop_suffix_table& x)
  {
    if (this != &x)
    {
      static_cast< ::xml_schema::type& > (*this) = x;
      this->world_drop_suffix_template_ = x.world_drop_suffix_template_;
    }

    return *this;
  }

  world_drop_suffix_table::
  ~world_drop_suffix_table ()
  {
  }
}

#include <istream>
#include <xsd/cxx/xml/sax/std-input-source.hxx>
#include <xsd/cxx/tree/error-handler.hxx>

namespace gdt
{
  ::std::unique_ptr< ::gdt::world_drop_suffix_table >
  world_drop_suffix_table_ (const ::std::wstring& u,
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

    return ::std::unique_ptr< ::gdt::world_drop_suffix_table > (
      ::gdt::world_drop_suffix_table_ (
        std::move (d), f | ::xml_schema::flags::own_dom, p));
  }

  ::std::unique_ptr< ::gdt::world_drop_suffix_table >
  world_drop_suffix_table_ (const ::std::wstring& u,
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

    return ::std::unique_ptr< ::gdt::world_drop_suffix_table > (
      ::gdt::world_drop_suffix_table_ (
        std::move (d), f | ::xml_schema::flags::own_dom, p));
  }

  ::std::unique_ptr< ::gdt::world_drop_suffix_table >
  world_drop_suffix_table_ (const ::std::wstring& u,
                            ::xercesc::DOMErrorHandler& h,
                            ::xml_schema::flags f,
                            const ::xml_schema::properties& p)
  {
    ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
      ::xsd::cxx::xml::dom::parse< wchar_t > (
        u, h, p, f));

    if (!d.get ())
      throw ::xsd::cxx::tree::parsing< wchar_t > ();

    return ::std::unique_ptr< ::gdt::world_drop_suffix_table > (
      ::gdt::world_drop_suffix_table_ (
        std::move (d), f | ::xml_schema::flags::own_dom, p));
  }

  ::std::unique_ptr< ::gdt::world_drop_suffix_table >
  world_drop_suffix_table_ (::std::istream& is,
                            ::xml_schema::flags f,
                            const ::xml_schema::properties& p)
  {
    ::xsd::cxx::xml::auto_initializer i (
      (f & ::xml_schema::flags::dont_initialize) == 0,
      (f & ::xml_schema::flags::keep_dom) == 0);

    ::xsd::cxx::xml::sax::std_input_source isrc (is);
    return ::gdt::world_drop_suffix_table_ (isrc, f, p);
  }

  ::std::unique_ptr< ::gdt::world_drop_suffix_table >
  world_drop_suffix_table_ (::std::istream& is,
                            ::xml_schema::error_handler& h,
                            ::xml_schema::flags f,
                            const ::xml_schema::properties& p)
  {
    ::xsd::cxx::xml::auto_initializer i (
      (f & ::xml_schema::flags::dont_initialize) == 0,
      (f & ::xml_schema::flags::keep_dom) == 0);

    ::xsd::cxx::xml::sax::std_input_source isrc (is);
    return ::gdt::world_drop_suffix_table_ (isrc, h, f, p);
  }

  ::std::unique_ptr< ::gdt::world_drop_suffix_table >
  world_drop_suffix_table_ (::std::istream& is,
                            ::xercesc::DOMErrorHandler& h,
                            ::xml_schema::flags f,
                            const ::xml_schema::properties& p)
  {
    ::xsd::cxx::xml::sax::std_input_source isrc (is);
    return ::gdt::world_drop_suffix_table_ (isrc, h, f, p);
  }

  ::std::unique_ptr< ::gdt::world_drop_suffix_table >
  world_drop_suffix_table_ (::std::istream& is,
                            const ::std::wstring& sid,
                            ::xml_schema::flags f,
                            const ::xml_schema::properties& p)
  {
    ::xsd::cxx::xml::auto_initializer i (
      (f & ::xml_schema::flags::dont_initialize) == 0,
      (f & ::xml_schema::flags::keep_dom) == 0);

    ::xsd::cxx::xml::sax::std_input_source isrc (is, sid);
    return ::gdt::world_drop_suffix_table_ (isrc, f, p);
  }

  ::std::unique_ptr< ::gdt::world_drop_suffix_table >
  world_drop_suffix_table_ (::std::istream& is,
                            const ::std::wstring& sid,
                            ::xml_schema::error_handler& h,
                            ::xml_schema::flags f,
                            const ::xml_schema::properties& p)
  {
    ::xsd::cxx::xml::auto_initializer i (
      (f & ::xml_schema::flags::dont_initialize) == 0,
      (f & ::xml_schema::flags::keep_dom) == 0);

    ::xsd::cxx::xml::sax::std_input_source isrc (is, sid);
    return ::gdt::world_drop_suffix_table_ (isrc, h, f, p);
  }

  ::std::unique_ptr< ::gdt::world_drop_suffix_table >
  world_drop_suffix_table_ (::std::istream& is,
                            const ::std::wstring& sid,
                            ::xercesc::DOMErrorHandler& h,
                            ::xml_schema::flags f,
                            const ::xml_schema::properties& p)
  {
    ::xsd::cxx::xml::sax::std_input_source isrc (is, sid);
    return ::gdt::world_drop_suffix_table_ (isrc, h, f, p);
  }

  ::std::unique_ptr< ::gdt::world_drop_suffix_table >
  world_drop_suffix_table_ (::xercesc::InputSource& i,
                            ::xml_schema::flags f,
                            const ::xml_schema::properties& p)
  {
    ::xsd::cxx::tree::error_handler< wchar_t > h;

    ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
      ::xsd::cxx::xml::dom::parse< wchar_t > (
        i, h, p, f));

    h.throw_if_failed< ::xsd::cxx::tree::parsing< wchar_t > > ();

    return ::std::unique_ptr< ::gdt::world_drop_suffix_table > (
      ::gdt::world_drop_suffix_table_ (
        std::move (d), f | ::xml_schema::flags::own_dom, p));
  }

  ::std::unique_ptr< ::gdt::world_drop_suffix_table >
  world_drop_suffix_table_ (::xercesc::InputSource& i,
                            ::xml_schema::error_handler& h,
                            ::xml_schema::flags f,
                            const ::xml_schema::properties& p)
  {
    ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
      ::xsd::cxx::xml::dom::parse< wchar_t > (
        i, h, p, f));

    if (!d.get ())
      throw ::xsd::cxx::tree::parsing< wchar_t > ();

    return ::std::unique_ptr< ::gdt::world_drop_suffix_table > (
      ::gdt::world_drop_suffix_table_ (
        std::move (d), f | ::xml_schema::flags::own_dom, p));
  }

  ::std::unique_ptr< ::gdt::world_drop_suffix_table >
  world_drop_suffix_table_ (::xercesc::InputSource& i,
                            ::xercesc::DOMErrorHandler& h,
                            ::xml_schema::flags f,
                            const ::xml_schema::properties& p)
  {
    ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
      ::xsd::cxx::xml::dom::parse< wchar_t > (
        i, h, p, f));

    if (!d.get ())
      throw ::xsd::cxx::tree::parsing< wchar_t > ();

    return ::std::unique_ptr< ::gdt::world_drop_suffix_table > (
      ::gdt::world_drop_suffix_table_ (
        std::move (d), f | ::xml_schema::flags::own_dom, p));
  }

  ::std::unique_ptr< ::gdt::world_drop_suffix_table >
  world_drop_suffix_table_ (const ::xercesc::DOMDocument& doc,
                            ::xml_schema::flags f,
                            const ::xml_schema::properties& p)
  {
    if (f & ::xml_schema::flags::keep_dom)
    {
      ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
        static_cast< ::xercesc::DOMDocument* > (doc.cloneNode (true)));

      return ::std::unique_ptr< ::gdt::world_drop_suffix_table > (
        ::gdt::world_drop_suffix_table_ (
          std::move (d), f | ::xml_schema::flags::own_dom, p));
    }

    const ::xercesc::DOMElement& e (*doc.getDocumentElement ());
    const ::xsd::cxx::xml::qualified_name< wchar_t > n (
      ::xsd::cxx::xml::dom::name< wchar_t > (e));

    if (n.name () == L"world_drop_suffix_table" &&
        n.namespace_ () == L"")
    {
      ::std::unique_ptr< ::gdt::world_drop_suffix_table > r (
        ::xsd::cxx::tree::traits< ::gdt::world_drop_suffix_table, wchar_t >::create (
          e, f, 0));
      return r;
    }

    throw ::xsd::cxx::tree::unexpected_element < wchar_t > (
      n.name (),
      n.namespace_ (),
      L"world_drop_suffix_table",
      L"");
  }

  ::std::unique_ptr< ::gdt::world_drop_suffix_table >
  world_drop_suffix_table_ (::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d,
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

    if (n.name () == L"world_drop_suffix_table" &&
        n.namespace_ () == L"")
    {
      ::std::unique_ptr< ::gdt::world_drop_suffix_table > r (
        ::xsd::cxx::tree::traits< ::gdt::world_drop_suffix_table, wchar_t >::create (
          e, f, 0));
      return r;
    }

    throw ::xsd::cxx::tree::unexpected_element < wchar_t > (
      n.name (),
      n.namespace_ (),
      L"world_drop_suffix_table",
      L"");
  }
}

#include <ostream>
#include <xsd/cxx/tree/error-handler.hxx>
#include <xsd/cxx/xml/dom/serialization-source.hxx>

namespace gdt
{
  void
  world_drop_suffix_table_ (::std::ostream& o,
                            const ::gdt::world_drop_suffix_table& s,
                            const ::xml_schema::namespace_infomap& m,
                            const ::std::wstring& e,
                            ::xml_schema::flags f)
  {
    ::xsd::cxx::xml::auto_initializer i (
      (f & ::xml_schema::flags::dont_initialize) == 0);

    ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
      ::gdt::world_drop_suffix_table_ (s, m, f));

    ::xsd::cxx::tree::error_handler< wchar_t > h;

    ::xsd::cxx::xml::dom::ostream_format_target t (o);
    if (!::xsd::cxx::xml::dom::serialize (t, *d, e, h, f))
    {
      h.throw_if_failed< ::xsd::cxx::tree::serialization< wchar_t > > ();
    }
  }

  void
  world_drop_suffix_table_ (::std::ostream& o,
                            const ::gdt::world_drop_suffix_table& s,
                            ::xml_schema::error_handler& h,
                            const ::xml_schema::namespace_infomap& m,
                            const ::std::wstring& e,
                            ::xml_schema::flags f)
  {
    ::xsd::cxx::xml::auto_initializer i (
      (f & ::xml_schema::flags::dont_initialize) == 0);

    ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
      ::gdt::world_drop_suffix_table_ (s, m, f));
    ::xsd::cxx::xml::dom::ostream_format_target t (o);
    if (!::xsd::cxx::xml::dom::serialize (t, *d, e, h, f))
    {
      throw ::xsd::cxx::tree::serialization< wchar_t > ();
    }
  }

  void
  world_drop_suffix_table_ (::std::ostream& o,
                            const ::gdt::world_drop_suffix_table& s,
                            ::xercesc::DOMErrorHandler& h,
                            const ::xml_schema::namespace_infomap& m,
                            const ::std::wstring& e,
                            ::xml_schema::flags f)
  {
    ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
      ::gdt::world_drop_suffix_table_ (s, m, f));
    ::xsd::cxx::xml::dom::ostream_format_target t (o);
    if (!::xsd::cxx::xml::dom::serialize (t, *d, e, h, f))
    {
      throw ::xsd::cxx::tree::serialization< wchar_t > ();
    }
  }

  void
  world_drop_suffix_table_ (::xercesc::XMLFormatTarget& t,
                            const ::gdt::world_drop_suffix_table& s,
                            const ::xml_schema::namespace_infomap& m,
                            const ::std::wstring& e,
                            ::xml_schema::flags f)
  {
    ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
      ::gdt::world_drop_suffix_table_ (s, m, f));

    ::xsd::cxx::tree::error_handler< wchar_t > h;

    if (!::xsd::cxx::xml::dom::serialize (t, *d, e, h, f))
    {
      h.throw_if_failed< ::xsd::cxx::tree::serialization< wchar_t > > ();
    }
  }

  void
  world_drop_suffix_table_ (::xercesc::XMLFormatTarget& t,
                            const ::gdt::world_drop_suffix_table& s,
                            ::xml_schema::error_handler& h,
                            const ::xml_schema::namespace_infomap& m,
                            const ::std::wstring& e,
                            ::xml_schema::flags f)
  {
    ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
      ::gdt::world_drop_suffix_table_ (s, m, f));
    if (!::xsd::cxx::xml::dom::serialize (t, *d, e, h, f))
    {
      throw ::xsd::cxx::tree::serialization< wchar_t > ();
    }
  }

  void
  world_drop_suffix_table_ (::xercesc::XMLFormatTarget& t,
                            const ::gdt::world_drop_suffix_table& s,
                            ::xercesc::DOMErrorHandler& h,
                            const ::xml_schema::namespace_infomap& m,
                            const ::std::wstring& e,
                            ::xml_schema::flags f)
  {
    ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
      ::gdt::world_drop_suffix_table_ (s, m, f));
    if (!::xsd::cxx::xml::dom::serialize (t, *d, e, h, f))
    {
      throw ::xsd::cxx::tree::serialization< wchar_t > ();
    }
  }

  void
  world_drop_suffix_table_ (::xercesc::DOMDocument& d,
                            const ::gdt::world_drop_suffix_table& s,
                            ::xml_schema::flags)
  {
    ::xercesc::DOMElement& e (*d.getDocumentElement ());
    const ::xsd::cxx::xml::qualified_name< wchar_t > n (
      ::xsd::cxx::xml::dom::name< wchar_t > (e));

    if (n.name () == L"world_drop_suffix_table" &&
        n.namespace_ () == L"")
    {
      e << s;
    }
    else
    {
      throw ::xsd::cxx::tree::unexpected_element < wchar_t > (
        n.name (),
        n.namespace_ (),
        L"world_drop_suffix_table",
        L"");
    }
  }

  ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument >
  world_drop_suffix_table_ (const ::gdt::world_drop_suffix_table& s,
                            const ::xml_schema::namespace_infomap& m,
                            ::xml_schema::flags f)
  {
    ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
      ::xsd::cxx::xml::dom::serialize< wchar_t > (
        L"world_drop_suffix_table",
        L"",
        m, f));

    ::gdt::world_drop_suffix_table_ (*d, s, f);
    return d;
  }

  void
  operator<< (::xercesc::DOMElement& e, const world_drop_suffix_t& i)
  {
    e << static_cast< const ::xml_schema::type& > (i);

    // index
    //
    {
      ::xercesc::DOMAttr& a (
        ::xsd::cxx::xml::dom::create_attribute (
          L"index",
          e));

      a << i.index ();
    }

    // world_drop_id_1
    //
    {
      ::xercesc::DOMAttr& a (
        ::xsd::cxx::xml::dom::create_attribute (
          L"world_drop_id_1",
          e));

      a << i.world_drop_id_1 ();
    }

    // world_drop_id_2
    //
    {
      ::xercesc::DOMAttr& a (
        ::xsd::cxx::xml::dom::create_attribute (
          L"world_drop_id_2",
          e));

      a << i.world_drop_id_2 ();
    }

    // world_drop_id_3
    //
    {
      ::xercesc::DOMAttr& a (
        ::xsd::cxx::xml::dom::create_attribute (
          L"world_drop_id_3",
          e));

      a << i.world_drop_id_3 ();
    }

    // world_drop_id_4
    //
    {
      ::xercesc::DOMAttr& a (
        ::xsd::cxx::xml::dom::create_attribute (
          L"world_drop_id_4",
          e));

      a << i.world_drop_id_4 ();
    }

    // world_drop_id_5
    //
    {
      ::xercesc::DOMAttr& a (
        ::xsd::cxx::xml::dom::create_attribute (
          L"world_drop_id_5",
          e));

      a << i.world_drop_id_5 ();
    }

    // loop_count
    //
    {
      ::xercesc::DOMAttr& a (
        ::xsd::cxx::xml::dom::create_attribute (
          L"loop_count",
          e));

      a << i.loop_count ();
    }

    // drop_pct
    //
    {
      ::xercesc::DOMAttr& a (
        ::xsd::cxx::xml::dom::create_attribute (
          L"drop_pct",
          e));

      a << i.drop_pct ();
    }
  }

  void
  operator<< (::xercesc::DOMElement& e, const world_drop_suffix_table& i)
  {
    e << static_cast< const ::xml_schema::type& > (i);

    // world_drop_suffix_template
    //
    for (world_drop_suffix_table::world_drop_suffix_template_const_iterator
         b (i.world_drop_suffix_template ().begin ()), n (i.world_drop_suffix_template ().end ());
         b != n; ++b)
    {
      ::xercesc::DOMElement& s (
        ::xsd::cxx::xml::dom::create_element (
          L"world_drop_suffix_template",
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

