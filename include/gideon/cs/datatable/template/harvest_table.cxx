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

#include "harvest_table.hxx"

#include <xsd/cxx/xml/dom/parsing-source.hxx>

namespace gdt
{
  // harvest_t
  //

  harvest_t::
  harvest_t ()
  : ::xml_schema::type (),
    harvest_code_ (this),
    live_mil_sec_ (this),
    harvest_mil_sec_ (this),
    min_harvest_count_ (this),
    max_harvest_count_ (this),
    item_drop_id_ (this),
    modeling_name_ (this),
    rate_scale_by_count_ (this),
    animation_name_ (this),
    harvest_use_item_ (this),
    harvest_effect_ (this),
    display_effect_ (this),
    minimap_icon_name_ (this)
  {
  }

  harvest_t::
  harvest_t (const harvest_code_type& harvest_code,
             const live_mil_sec_type& live_mil_sec,
             const harvest_mil_sec_type& harvest_mil_sec,
             const min_harvest_count_type& min_harvest_count,
             const max_harvest_count_type& max_harvest_count,
             const item_drop_id_type& item_drop_id,
             const modeling_name_type& modeling_name,
             const rate_scale_by_count_type& rate_scale_by_count,
             const animation_name_type& animation_name,
             const harvest_use_item_type& harvest_use_item,
             const harvest_effect_type& harvest_effect,
             const display_effect_type& display_effect,
             const minimap_icon_name_type& minimap_icon_name)
  : ::xml_schema::type (),
    harvest_code_ (harvest_code, this),
    live_mil_sec_ (live_mil_sec, this),
    harvest_mil_sec_ (harvest_mil_sec, this),
    min_harvest_count_ (min_harvest_count, this),
    max_harvest_count_ (max_harvest_count, this),
    item_drop_id_ (item_drop_id, this),
    modeling_name_ (modeling_name, this),
    rate_scale_by_count_ (rate_scale_by_count, this),
    animation_name_ (animation_name, this),
    harvest_use_item_ (harvest_use_item, this),
    harvest_effect_ (harvest_effect, this),
    display_effect_ (display_effect, this),
    minimap_icon_name_ (minimap_icon_name, this)
  {
  }

  harvest_t::
  harvest_t (const harvest_t& x,
             ::xml_schema::flags f,
             ::xml_schema::container* c)
  : ::xml_schema::type (x, f, c),
    harvest_code_ (x.harvest_code_, f, this),
    live_mil_sec_ (x.live_mil_sec_, f, this),
    harvest_mil_sec_ (x.harvest_mil_sec_, f, this),
    min_harvest_count_ (x.min_harvest_count_, f, this),
    max_harvest_count_ (x.max_harvest_count_, f, this),
    item_drop_id_ (x.item_drop_id_, f, this),
    modeling_name_ (x.modeling_name_, f, this),
    rate_scale_by_count_ (x.rate_scale_by_count_, f, this),
    animation_name_ (x.animation_name_, f, this),
    harvest_use_item_ (x.harvest_use_item_, f, this),
    harvest_effect_ (x.harvest_effect_, f, this),
    display_effect_ (x.display_effect_, f, this),
    minimap_icon_name_ (x.minimap_icon_name_, f, this)
  {
  }

  harvest_t::
  harvest_t (const ::xercesc::DOMElement& e,
             ::xml_schema::flags f,
             ::xml_schema::container* c)
  : ::xml_schema::type (e, f | ::xml_schema::flags::base, c),
    harvest_code_ (this),
    live_mil_sec_ (this),
    harvest_mil_sec_ (this),
    min_harvest_count_ (this),
    max_harvest_count_ (this),
    item_drop_id_ (this),
    modeling_name_ (this),
    rate_scale_by_count_ (this),
    animation_name_ (this),
    harvest_use_item_ (this),
    harvest_effect_ (this),
    display_effect_ (this),
    minimap_icon_name_ (this)
  {
    if ((f & ::xml_schema::flags::base) == 0)
    {
      ::xsd::cxx::xml::dom::parser< wchar_t > p (e, false, false, true);
      this->parse (p, f);
    }
  }

  void harvest_t::
  parse (::xsd::cxx::xml::dom::parser< wchar_t >& p,
         ::xml_schema::flags f)
  {
    while (p.more_attributes ())
    {
      const ::xercesc::DOMAttr& i (p.next_attribute ());
      const ::xsd::cxx::xml::qualified_name< wchar_t > n (
        ::xsd::cxx::xml::dom::name< wchar_t > (i));

      if (n.name () == L"harvest_code" && n.namespace_ ().empty ())
      {
        this->harvest_code_.set (harvest_code_traits::create (i, f, this));
        continue;
      }

      if (n.name () == L"live_mil_sec" && n.namespace_ ().empty ())
      {
        this->live_mil_sec_.set (live_mil_sec_traits::create (i, f, this));
        continue;
      }

      if (n.name () == L"harvest_mil_sec" && n.namespace_ ().empty ())
      {
        this->harvest_mil_sec_.set (harvest_mil_sec_traits::create (i, f, this));
        continue;
      }

      if (n.name () == L"min_harvest_count" && n.namespace_ ().empty ())
      {
        this->min_harvest_count_.set (min_harvest_count_traits::create (i, f, this));
        continue;
      }

      if (n.name () == L"max_harvest_count" && n.namespace_ ().empty ())
      {
        this->max_harvest_count_.set (max_harvest_count_traits::create (i, f, this));
        continue;
      }

      if (n.name () == L"item_drop_id" && n.namespace_ ().empty ())
      {
        this->item_drop_id_.set (item_drop_id_traits::create (i, f, this));
        continue;
      }

      if (n.name () == L"modeling_name" && n.namespace_ ().empty ())
      {
        this->modeling_name_.set (modeling_name_traits::create (i, f, this));
        continue;
      }

      if (n.name () == L"rate_scale_by_count" && n.namespace_ ().empty ())
      {
        this->rate_scale_by_count_.set (rate_scale_by_count_traits::create (i, f, this));
        continue;
      }

      if (n.name () == L"animation_name" && n.namespace_ ().empty ())
      {
        this->animation_name_.set (animation_name_traits::create (i, f, this));
        continue;
      }

      if (n.name () == L"harvest_use_item" && n.namespace_ ().empty ())
      {
        this->harvest_use_item_.set (harvest_use_item_traits::create (i, f, this));
        continue;
      }

      if (n.name () == L"harvest_effect" && n.namespace_ ().empty ())
      {
        this->harvest_effect_.set (harvest_effect_traits::create (i, f, this));
        continue;
      }

      if (n.name () == L"display_effect" && n.namespace_ ().empty ())
      {
        this->display_effect_.set (display_effect_traits::create (i, f, this));
        continue;
      }

      if (n.name () == L"minimap_icon_name" && n.namespace_ ().empty ())
      {
        this->minimap_icon_name_.set (minimap_icon_name_traits::create (i, f, this));
        continue;
      }
    }

    if (!harvest_code_.present ())
    {
      throw ::xsd::cxx::tree::expected_attribute< wchar_t > (
        L"harvest_code",
        L"");
    }

    if (!live_mil_sec_.present ())
    {
      throw ::xsd::cxx::tree::expected_attribute< wchar_t > (
        L"live_mil_sec",
        L"");
    }

    if (!harvest_mil_sec_.present ())
    {
      throw ::xsd::cxx::tree::expected_attribute< wchar_t > (
        L"harvest_mil_sec",
        L"");
    }

    if (!min_harvest_count_.present ())
    {
      throw ::xsd::cxx::tree::expected_attribute< wchar_t > (
        L"min_harvest_count",
        L"");
    }

    if (!max_harvest_count_.present ())
    {
      throw ::xsd::cxx::tree::expected_attribute< wchar_t > (
        L"max_harvest_count",
        L"");
    }

    if (!item_drop_id_.present ())
    {
      throw ::xsd::cxx::tree::expected_attribute< wchar_t > (
        L"item_drop_id",
        L"");
    }

    if (!modeling_name_.present ())
    {
      throw ::xsd::cxx::tree::expected_attribute< wchar_t > (
        L"modeling_name",
        L"");
    }

    if (!rate_scale_by_count_.present ())
    {
      throw ::xsd::cxx::tree::expected_attribute< wchar_t > (
        L"rate_scale_by_count",
        L"");
    }

    if (!animation_name_.present ())
    {
      throw ::xsd::cxx::tree::expected_attribute< wchar_t > (
        L"animation_name",
        L"");
    }

    if (!harvest_use_item_.present ())
    {
      throw ::xsd::cxx::tree::expected_attribute< wchar_t > (
        L"harvest_use_item",
        L"");
    }

    if (!harvest_effect_.present ())
    {
      throw ::xsd::cxx::tree::expected_attribute< wchar_t > (
        L"harvest_effect",
        L"");
    }

    if (!display_effect_.present ())
    {
      throw ::xsd::cxx::tree::expected_attribute< wchar_t > (
        L"display_effect",
        L"");
    }

    if (!minimap_icon_name_.present ())
    {
      throw ::xsd::cxx::tree::expected_attribute< wchar_t > (
        L"minimap_icon_name",
        L"");
    }
  }

  harvest_t* harvest_t::
  _clone (::xml_schema::flags f,
          ::xml_schema::container* c) const
  {
    return new class harvest_t (*this, f, c);
  }

  harvest_t& harvest_t::
  operator= (const harvest_t& x)
  {
    if (this != &x)
    {
      static_cast< ::xml_schema::type& > (*this) = x;
      this->harvest_code_ = x.harvest_code_;
      this->live_mil_sec_ = x.live_mil_sec_;
      this->harvest_mil_sec_ = x.harvest_mil_sec_;
      this->min_harvest_count_ = x.min_harvest_count_;
      this->max_harvest_count_ = x.max_harvest_count_;
      this->item_drop_id_ = x.item_drop_id_;
      this->modeling_name_ = x.modeling_name_;
      this->rate_scale_by_count_ = x.rate_scale_by_count_;
      this->animation_name_ = x.animation_name_;
      this->harvest_use_item_ = x.harvest_use_item_;
      this->harvest_effect_ = x.harvest_effect_;
      this->display_effect_ = x.display_effect_;
      this->minimap_icon_name_ = x.minimap_icon_name_;
    }

    return *this;
  }

  harvest_t::
  ~harvest_t ()
  {
  }

  // harvest_table
  //

  harvest_table::
  harvest_table ()
  : ::xml_schema::type (),
    harvest_template_ (this)
  {
  }

  harvest_table::
  harvest_table (const harvest_table& x,
                 ::xml_schema::flags f,
                 ::xml_schema::container* c)
  : ::xml_schema::type (x, f, c),
    harvest_template_ (x.harvest_template_, f, this)
  {
  }

  harvest_table::
  harvest_table (const ::xercesc::DOMElement& e,
                 ::xml_schema::flags f,
                 ::xml_schema::container* c)
  : ::xml_schema::type (e, f | ::xml_schema::flags::base, c),
    harvest_template_ (this)
  {
    if ((f & ::xml_schema::flags::base) == 0)
    {
      ::xsd::cxx::xml::dom::parser< wchar_t > p (e, true, false, false);
      this->parse (p, f);
    }
  }

  void harvest_table::
  parse (::xsd::cxx::xml::dom::parser< wchar_t >& p,
         ::xml_schema::flags f)
  {
    for (; p.more_content (); p.next_content (false))
    {
      const ::xercesc::DOMElement& i (p.cur_element ());
      const ::xsd::cxx::xml::qualified_name< wchar_t > n (
        ::xsd::cxx::xml::dom::name< wchar_t > (i));

      // harvest_template
      //
      if (n.name () == L"harvest_template" && n.namespace_ ().empty ())
      {
        ::std::unique_ptr< harvest_template_type > r (
          harvest_template_traits::create (i, f, this));

        this->harvest_template_.push_back (::std::move (r));
        continue;
      }

      break;
    }
  }

  harvest_table* harvest_table::
  _clone (::xml_schema::flags f,
          ::xml_schema::container* c) const
  {
    return new class harvest_table (*this, f, c);
  }

  harvest_table& harvest_table::
  operator= (const harvest_table& x)
  {
    if (this != &x)
    {
      static_cast< ::xml_schema::type& > (*this) = x;
      this->harvest_template_ = x.harvest_template_;
    }

    return *this;
  }

  harvest_table::
  ~harvest_table ()
  {
  }
}

#include <istream>
#include <xsd/cxx/xml/sax/std-input-source.hxx>
#include <xsd/cxx/tree/error-handler.hxx>

namespace gdt
{
  ::std::unique_ptr< ::gdt::harvest_table >
  harvest_table_ (const ::std::wstring& u,
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

    return ::std::unique_ptr< ::gdt::harvest_table > (
      ::gdt::harvest_table_ (
        std::move (d), f | ::xml_schema::flags::own_dom, p));
  }

  ::std::unique_ptr< ::gdt::harvest_table >
  harvest_table_ (const ::std::wstring& u,
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

    return ::std::unique_ptr< ::gdt::harvest_table > (
      ::gdt::harvest_table_ (
        std::move (d), f | ::xml_schema::flags::own_dom, p));
  }

  ::std::unique_ptr< ::gdt::harvest_table >
  harvest_table_ (const ::std::wstring& u,
                  ::xercesc::DOMErrorHandler& h,
                  ::xml_schema::flags f,
                  const ::xml_schema::properties& p)
  {
    ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
      ::xsd::cxx::xml::dom::parse< wchar_t > (
        u, h, p, f));

    if (!d.get ())
      throw ::xsd::cxx::tree::parsing< wchar_t > ();

    return ::std::unique_ptr< ::gdt::harvest_table > (
      ::gdt::harvest_table_ (
        std::move (d), f | ::xml_schema::flags::own_dom, p));
  }

  ::std::unique_ptr< ::gdt::harvest_table >
  harvest_table_ (::std::istream& is,
                  ::xml_schema::flags f,
                  const ::xml_schema::properties& p)
  {
    ::xsd::cxx::xml::auto_initializer i (
      (f & ::xml_schema::flags::dont_initialize) == 0,
      (f & ::xml_schema::flags::keep_dom) == 0);

    ::xsd::cxx::xml::sax::std_input_source isrc (is);
    return ::gdt::harvest_table_ (isrc, f, p);
  }

  ::std::unique_ptr< ::gdt::harvest_table >
  harvest_table_ (::std::istream& is,
                  ::xml_schema::error_handler& h,
                  ::xml_schema::flags f,
                  const ::xml_schema::properties& p)
  {
    ::xsd::cxx::xml::auto_initializer i (
      (f & ::xml_schema::flags::dont_initialize) == 0,
      (f & ::xml_schema::flags::keep_dom) == 0);

    ::xsd::cxx::xml::sax::std_input_source isrc (is);
    return ::gdt::harvest_table_ (isrc, h, f, p);
  }

  ::std::unique_ptr< ::gdt::harvest_table >
  harvest_table_ (::std::istream& is,
                  ::xercesc::DOMErrorHandler& h,
                  ::xml_schema::flags f,
                  const ::xml_schema::properties& p)
  {
    ::xsd::cxx::xml::sax::std_input_source isrc (is);
    return ::gdt::harvest_table_ (isrc, h, f, p);
  }

  ::std::unique_ptr< ::gdt::harvest_table >
  harvest_table_ (::std::istream& is,
                  const ::std::wstring& sid,
                  ::xml_schema::flags f,
                  const ::xml_schema::properties& p)
  {
    ::xsd::cxx::xml::auto_initializer i (
      (f & ::xml_schema::flags::dont_initialize) == 0,
      (f & ::xml_schema::flags::keep_dom) == 0);

    ::xsd::cxx::xml::sax::std_input_source isrc (is, sid);
    return ::gdt::harvest_table_ (isrc, f, p);
  }

  ::std::unique_ptr< ::gdt::harvest_table >
  harvest_table_ (::std::istream& is,
                  const ::std::wstring& sid,
                  ::xml_schema::error_handler& h,
                  ::xml_schema::flags f,
                  const ::xml_schema::properties& p)
  {
    ::xsd::cxx::xml::auto_initializer i (
      (f & ::xml_schema::flags::dont_initialize) == 0,
      (f & ::xml_schema::flags::keep_dom) == 0);

    ::xsd::cxx::xml::sax::std_input_source isrc (is, sid);
    return ::gdt::harvest_table_ (isrc, h, f, p);
  }

  ::std::unique_ptr< ::gdt::harvest_table >
  harvest_table_ (::std::istream& is,
                  const ::std::wstring& sid,
                  ::xercesc::DOMErrorHandler& h,
                  ::xml_schema::flags f,
                  const ::xml_schema::properties& p)
  {
    ::xsd::cxx::xml::sax::std_input_source isrc (is, sid);
    return ::gdt::harvest_table_ (isrc, h, f, p);
  }

  ::std::unique_ptr< ::gdt::harvest_table >
  harvest_table_ (::xercesc::InputSource& i,
                  ::xml_schema::flags f,
                  const ::xml_schema::properties& p)
  {
    ::xsd::cxx::tree::error_handler< wchar_t > h;

    ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
      ::xsd::cxx::xml::dom::parse< wchar_t > (
        i, h, p, f));

    h.throw_if_failed< ::xsd::cxx::tree::parsing< wchar_t > > ();

    return ::std::unique_ptr< ::gdt::harvest_table > (
      ::gdt::harvest_table_ (
        std::move (d), f | ::xml_schema::flags::own_dom, p));
  }

  ::std::unique_ptr< ::gdt::harvest_table >
  harvest_table_ (::xercesc::InputSource& i,
                  ::xml_schema::error_handler& h,
                  ::xml_schema::flags f,
                  const ::xml_schema::properties& p)
  {
    ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
      ::xsd::cxx::xml::dom::parse< wchar_t > (
        i, h, p, f));

    if (!d.get ())
      throw ::xsd::cxx::tree::parsing< wchar_t > ();

    return ::std::unique_ptr< ::gdt::harvest_table > (
      ::gdt::harvest_table_ (
        std::move (d), f | ::xml_schema::flags::own_dom, p));
  }

  ::std::unique_ptr< ::gdt::harvest_table >
  harvest_table_ (::xercesc::InputSource& i,
                  ::xercesc::DOMErrorHandler& h,
                  ::xml_schema::flags f,
                  const ::xml_schema::properties& p)
  {
    ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
      ::xsd::cxx::xml::dom::parse< wchar_t > (
        i, h, p, f));

    if (!d.get ())
      throw ::xsd::cxx::tree::parsing< wchar_t > ();

    return ::std::unique_ptr< ::gdt::harvest_table > (
      ::gdt::harvest_table_ (
        std::move (d), f | ::xml_schema::flags::own_dom, p));
  }

  ::std::unique_ptr< ::gdt::harvest_table >
  harvest_table_ (const ::xercesc::DOMDocument& doc,
                  ::xml_schema::flags f,
                  const ::xml_schema::properties& p)
  {
    if (f & ::xml_schema::flags::keep_dom)
    {
      ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
        static_cast< ::xercesc::DOMDocument* > (doc.cloneNode (true)));

      return ::std::unique_ptr< ::gdt::harvest_table > (
        ::gdt::harvest_table_ (
          std::move (d), f | ::xml_schema::flags::own_dom, p));
    }

    const ::xercesc::DOMElement& e (*doc.getDocumentElement ());
    const ::xsd::cxx::xml::qualified_name< wchar_t > n (
      ::xsd::cxx::xml::dom::name< wchar_t > (e));

    if (n.name () == L"harvest_table" &&
        n.namespace_ () == L"")
    {
      ::std::unique_ptr< ::gdt::harvest_table > r (
        ::xsd::cxx::tree::traits< ::gdt::harvest_table, wchar_t >::create (
          e, f, 0));
      return r;
    }

    throw ::xsd::cxx::tree::unexpected_element < wchar_t > (
      n.name (),
      n.namespace_ (),
      L"harvest_table",
      L"");
  }

  ::std::unique_ptr< ::gdt::harvest_table >
  harvest_table_ (::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d,
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

    if (n.name () == L"harvest_table" &&
        n.namespace_ () == L"")
    {
      ::std::unique_ptr< ::gdt::harvest_table > r (
        ::xsd::cxx::tree::traits< ::gdt::harvest_table, wchar_t >::create (
          e, f, 0));
      return r;
    }

    throw ::xsd::cxx::tree::unexpected_element < wchar_t > (
      n.name (),
      n.namespace_ (),
      L"harvest_table",
      L"");
  }
}

#include <ostream>
#include <xsd/cxx/tree/error-handler.hxx>
#include <xsd/cxx/xml/dom/serialization-source.hxx>

namespace gdt
{
  void
  harvest_table_ (::std::ostream& o,
                  const ::gdt::harvest_table& s,
                  const ::xml_schema::namespace_infomap& m,
                  const ::std::wstring& e,
                  ::xml_schema::flags f)
  {
    ::xsd::cxx::xml::auto_initializer i (
      (f & ::xml_schema::flags::dont_initialize) == 0);

    ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
      ::gdt::harvest_table_ (s, m, f));

    ::xsd::cxx::tree::error_handler< wchar_t > h;

    ::xsd::cxx::xml::dom::ostream_format_target t (o);
    if (!::xsd::cxx::xml::dom::serialize (t, *d, e, h, f))
    {
      h.throw_if_failed< ::xsd::cxx::tree::serialization< wchar_t > > ();
    }
  }

  void
  harvest_table_ (::std::ostream& o,
                  const ::gdt::harvest_table& s,
                  ::xml_schema::error_handler& h,
                  const ::xml_schema::namespace_infomap& m,
                  const ::std::wstring& e,
                  ::xml_schema::flags f)
  {
    ::xsd::cxx::xml::auto_initializer i (
      (f & ::xml_schema::flags::dont_initialize) == 0);

    ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
      ::gdt::harvest_table_ (s, m, f));
    ::xsd::cxx::xml::dom::ostream_format_target t (o);
    if (!::xsd::cxx::xml::dom::serialize (t, *d, e, h, f))
    {
      throw ::xsd::cxx::tree::serialization< wchar_t > ();
    }
  }

  void
  harvest_table_ (::std::ostream& o,
                  const ::gdt::harvest_table& s,
                  ::xercesc::DOMErrorHandler& h,
                  const ::xml_schema::namespace_infomap& m,
                  const ::std::wstring& e,
                  ::xml_schema::flags f)
  {
    ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
      ::gdt::harvest_table_ (s, m, f));
    ::xsd::cxx::xml::dom::ostream_format_target t (o);
    if (!::xsd::cxx::xml::dom::serialize (t, *d, e, h, f))
    {
      throw ::xsd::cxx::tree::serialization< wchar_t > ();
    }
  }

  void
  harvest_table_ (::xercesc::XMLFormatTarget& t,
                  const ::gdt::harvest_table& s,
                  const ::xml_schema::namespace_infomap& m,
                  const ::std::wstring& e,
                  ::xml_schema::flags f)
  {
    ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
      ::gdt::harvest_table_ (s, m, f));

    ::xsd::cxx::tree::error_handler< wchar_t > h;

    if (!::xsd::cxx::xml::dom::serialize (t, *d, e, h, f))
    {
      h.throw_if_failed< ::xsd::cxx::tree::serialization< wchar_t > > ();
    }
  }

  void
  harvest_table_ (::xercesc::XMLFormatTarget& t,
                  const ::gdt::harvest_table& s,
                  ::xml_schema::error_handler& h,
                  const ::xml_schema::namespace_infomap& m,
                  const ::std::wstring& e,
                  ::xml_schema::flags f)
  {
    ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
      ::gdt::harvest_table_ (s, m, f));
    if (!::xsd::cxx::xml::dom::serialize (t, *d, e, h, f))
    {
      throw ::xsd::cxx::tree::serialization< wchar_t > ();
    }
  }

  void
  harvest_table_ (::xercesc::XMLFormatTarget& t,
                  const ::gdt::harvest_table& s,
                  ::xercesc::DOMErrorHandler& h,
                  const ::xml_schema::namespace_infomap& m,
                  const ::std::wstring& e,
                  ::xml_schema::flags f)
  {
    ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
      ::gdt::harvest_table_ (s, m, f));
    if (!::xsd::cxx::xml::dom::serialize (t, *d, e, h, f))
    {
      throw ::xsd::cxx::tree::serialization< wchar_t > ();
    }
  }

  void
  harvest_table_ (::xercesc::DOMDocument& d,
                  const ::gdt::harvest_table& s,
                  ::xml_schema::flags)
  {
    ::xercesc::DOMElement& e (*d.getDocumentElement ());
    const ::xsd::cxx::xml::qualified_name< wchar_t > n (
      ::xsd::cxx::xml::dom::name< wchar_t > (e));

    if (n.name () == L"harvest_table" &&
        n.namespace_ () == L"")
    {
      e << s;
    }
    else
    {
      throw ::xsd::cxx::tree::unexpected_element < wchar_t > (
        n.name (),
        n.namespace_ (),
        L"harvest_table",
        L"");
    }
  }

  ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument >
  harvest_table_ (const ::gdt::harvest_table& s,
                  const ::xml_schema::namespace_infomap& m,
                  ::xml_schema::flags f)
  {
    ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
      ::xsd::cxx::xml::dom::serialize< wchar_t > (
        L"harvest_table",
        L"",
        m, f));

    ::gdt::harvest_table_ (*d, s, f);
    return d;
  }

  void
  operator<< (::xercesc::DOMElement& e, const harvest_t& i)
  {
    e << static_cast< const ::xml_schema::type& > (i);

    // harvest_code
    //
    {
      ::xercesc::DOMAttr& a (
        ::xsd::cxx::xml::dom::create_attribute (
          L"harvest_code",
          e));

      a << i.harvest_code ();
    }

    // live_mil_sec
    //
    {
      ::xercesc::DOMAttr& a (
        ::xsd::cxx::xml::dom::create_attribute (
          L"live_mil_sec",
          e));

      a << i.live_mil_sec ();
    }

    // harvest_mil_sec
    //
    {
      ::xercesc::DOMAttr& a (
        ::xsd::cxx::xml::dom::create_attribute (
          L"harvest_mil_sec",
          e));

      a << i.harvest_mil_sec ();
    }

    // min_harvest_count
    //
    {
      ::xercesc::DOMAttr& a (
        ::xsd::cxx::xml::dom::create_attribute (
          L"min_harvest_count",
          e));

      a << i.min_harvest_count ();
    }

    // max_harvest_count
    //
    {
      ::xercesc::DOMAttr& a (
        ::xsd::cxx::xml::dom::create_attribute (
          L"max_harvest_count",
          e));

      a << i.max_harvest_count ();
    }

    // item_drop_id
    //
    {
      ::xercesc::DOMAttr& a (
        ::xsd::cxx::xml::dom::create_attribute (
          L"item_drop_id",
          e));

      a << i.item_drop_id ();
    }

    // modeling_name
    //
    {
      ::xercesc::DOMAttr& a (
        ::xsd::cxx::xml::dom::create_attribute (
          L"modeling_name",
          e));

      a << i.modeling_name ();
    }

    // rate_scale_by_count
    //
    {
      ::xercesc::DOMAttr& a (
        ::xsd::cxx::xml::dom::create_attribute (
          L"rate_scale_by_count",
          e));

      a << i.rate_scale_by_count ();
    }

    // animation_name
    //
    {
      ::xercesc::DOMAttr& a (
        ::xsd::cxx::xml::dom::create_attribute (
          L"animation_name",
          e));

      a << i.animation_name ();
    }

    // harvest_use_item
    //
    {
      ::xercesc::DOMAttr& a (
        ::xsd::cxx::xml::dom::create_attribute (
          L"harvest_use_item",
          e));

      a << i.harvest_use_item ();
    }

    // harvest_effect
    //
    {
      ::xercesc::DOMAttr& a (
        ::xsd::cxx::xml::dom::create_attribute (
          L"harvest_effect",
          e));

      a << i.harvest_effect ();
    }

    // display_effect
    //
    {
      ::xercesc::DOMAttr& a (
        ::xsd::cxx::xml::dom::create_attribute (
          L"display_effect",
          e));

      a << i.display_effect ();
    }

    // minimap_icon_name
    //
    {
      ::xercesc::DOMAttr& a (
        ::xsd::cxx::xml::dom::create_attribute (
          L"minimap_icon_name",
          e));

      a << i.minimap_icon_name ();
    }
  }

  void
  operator<< (::xercesc::DOMElement& e, const harvest_table& i)
  {
    e << static_cast< const ::xml_schema::type& > (i);

    // harvest_template
    //
    for (harvest_table::harvest_template_const_iterator
         b (i.harvest_template ().begin ()), n (i.harvest_template ().end ());
         b != n; ++b)
    {
      ::xercesc::DOMElement& s (
        ::xsd::cxx::xml::dom::create_element (
          L"harvest_template",
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

