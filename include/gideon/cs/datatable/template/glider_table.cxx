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

#include "glider_table.hxx"

#include <xsd/cxx/xml/dom/parsing-source.hxx>

namespace gdt
{
  // glider_t
  //

  glider_t::
  glider_t ()
  : ::xml_schema::type (),
    glider_code_ (this),
    glider_icon_name_ (this),
    cast_time_ (this),
    org_speed_ (this),
    glide_durability_sec_ (this),
    repair_payment_ (this),
    glider_ready_anim_ (this),
    glider_modeling_name_ (this),
    glider_ready_sound_ (this),
    glider_flying_sound_ (this),
    glider_fold_sound_ (this),
    sell_cost_type_ (this),
    sell_cost_ (this),
    buy_cost_type_1_ (this),
    buy_cost_1_ (this),
    buy_cost_type_2_ (this),
    buy_cost_2_ (this)
  {
  }

  glider_t::
  glider_t (const glider_code_type& glider_code,
            const glider_icon_name_type& glider_icon_name,
            const cast_time_type& cast_time,
            const org_speed_type& org_speed,
            const glide_durability_sec_type& glide_durability_sec,
            const repair_payment_type& repair_payment,
            const glider_ready_anim_type& glider_ready_anim,
            const glider_modeling_name_type& glider_modeling_name,
            const glider_ready_sound_type& glider_ready_sound,
            const glider_flying_sound_type& glider_flying_sound,
            const glider_fold_sound_type& glider_fold_sound,
            const sell_cost_type_type& sell_cost_type,
            const sell_cost_type1& sell_cost,
            const buy_cost_type_1_type& buy_cost_type_1,
            const buy_cost_1_type& buy_cost_1,
            const buy_cost_type_2_type& buy_cost_type_2,
            const buy_cost_2_type& buy_cost_2)
  : ::xml_schema::type (),
    glider_code_ (glider_code, this),
    glider_icon_name_ (glider_icon_name, this),
    cast_time_ (cast_time, this),
    org_speed_ (org_speed, this),
    glide_durability_sec_ (glide_durability_sec, this),
    repair_payment_ (repair_payment, this),
    glider_ready_anim_ (glider_ready_anim, this),
    glider_modeling_name_ (glider_modeling_name, this),
    glider_ready_sound_ (glider_ready_sound, this),
    glider_flying_sound_ (glider_flying_sound, this),
    glider_fold_sound_ (glider_fold_sound, this),
    sell_cost_type_ (sell_cost_type, this),
    sell_cost_ (sell_cost, this),
    buy_cost_type_1_ (buy_cost_type_1, this),
    buy_cost_1_ (buy_cost_1, this),
    buy_cost_type_2_ (buy_cost_type_2, this),
    buy_cost_2_ (buy_cost_2, this)
  {
  }

  glider_t::
  glider_t (const glider_t& x,
            ::xml_schema::flags f,
            ::xml_schema::container* c)
  : ::xml_schema::type (x, f, c),
    glider_code_ (x.glider_code_, f, this),
    glider_icon_name_ (x.glider_icon_name_, f, this),
    cast_time_ (x.cast_time_, f, this),
    org_speed_ (x.org_speed_, f, this),
    glide_durability_sec_ (x.glide_durability_sec_, f, this),
    repair_payment_ (x.repair_payment_, f, this),
    glider_ready_anim_ (x.glider_ready_anim_, f, this),
    glider_modeling_name_ (x.glider_modeling_name_, f, this),
    glider_ready_sound_ (x.glider_ready_sound_, f, this),
    glider_flying_sound_ (x.glider_flying_sound_, f, this),
    glider_fold_sound_ (x.glider_fold_sound_, f, this),
    sell_cost_type_ (x.sell_cost_type_, f, this),
    sell_cost_ (x.sell_cost_, f, this),
    buy_cost_type_1_ (x.buy_cost_type_1_, f, this),
    buy_cost_1_ (x.buy_cost_1_, f, this),
    buy_cost_type_2_ (x.buy_cost_type_2_, f, this),
    buy_cost_2_ (x.buy_cost_2_, f, this)
  {
  }

  glider_t::
  glider_t (const ::xercesc::DOMElement& e,
            ::xml_schema::flags f,
            ::xml_schema::container* c)
  : ::xml_schema::type (e, f | ::xml_schema::flags::base, c),
    glider_code_ (this),
    glider_icon_name_ (this),
    cast_time_ (this),
    org_speed_ (this),
    glide_durability_sec_ (this),
    repair_payment_ (this),
    glider_ready_anim_ (this),
    glider_modeling_name_ (this),
    glider_ready_sound_ (this),
    glider_flying_sound_ (this),
    glider_fold_sound_ (this),
    sell_cost_type_ (this),
    sell_cost_ (this),
    buy_cost_type_1_ (this),
    buy_cost_1_ (this),
    buy_cost_type_2_ (this),
    buy_cost_2_ (this)
  {
    if ((f & ::xml_schema::flags::base) == 0)
    {
      ::xsd::cxx::xml::dom::parser< wchar_t > p (e, false, false, true);
      this->parse (p, f);
    }
  }

  void glider_t::
  parse (::xsd::cxx::xml::dom::parser< wchar_t >& p,
         ::xml_schema::flags f)
  {
    while (p.more_attributes ())
    {
      const ::xercesc::DOMAttr& i (p.next_attribute ());
      const ::xsd::cxx::xml::qualified_name< wchar_t > n (
        ::xsd::cxx::xml::dom::name< wchar_t > (i));

      if (n.name () == L"glider_code" && n.namespace_ ().empty ())
      {
        this->glider_code_.set (glider_code_traits::create (i, f, this));
        continue;
      }

      if (n.name () == L"glider_icon_name" && n.namespace_ ().empty ())
      {
        this->glider_icon_name_.set (glider_icon_name_traits::create (i, f, this));
        continue;
      }

      if (n.name () == L"cast_time" && n.namespace_ ().empty ())
      {
        this->cast_time_.set (cast_time_traits::create (i, f, this));
        continue;
      }

      if (n.name () == L"org_speed" && n.namespace_ ().empty ())
      {
        this->org_speed_.set (org_speed_traits::create (i, f, this));
        continue;
      }

      if (n.name () == L"glide_durability_sec" && n.namespace_ ().empty ())
      {
        this->glide_durability_sec_.set (glide_durability_sec_traits::create (i, f, this));
        continue;
      }

      if (n.name () == L"repair_payment" && n.namespace_ ().empty ())
      {
        this->repair_payment_.set (repair_payment_traits::create (i, f, this));
        continue;
      }

      if (n.name () == L"glider_ready_anim" && n.namespace_ ().empty ())
      {
        this->glider_ready_anim_.set (glider_ready_anim_traits::create (i, f, this));
        continue;
      }

      if (n.name () == L"glider_modeling_name" && n.namespace_ ().empty ())
      {
        this->glider_modeling_name_.set (glider_modeling_name_traits::create (i, f, this));
        continue;
      }

      if (n.name () == L"glider_ready_sound" && n.namespace_ ().empty ())
      {
        this->glider_ready_sound_.set (glider_ready_sound_traits::create (i, f, this));
        continue;
      }

      if (n.name () == L"glider_flying_sound" && n.namespace_ ().empty ())
      {
        this->glider_flying_sound_.set (glider_flying_sound_traits::create (i, f, this));
        continue;
      }

      if (n.name () == L"glider_fold_sound" && n.namespace_ ().empty ())
      {
        this->glider_fold_sound_.set (glider_fold_sound_traits::create (i, f, this));
        continue;
      }

      if (n.name () == L"sell_cost_type" && n.namespace_ ().empty ())
      {
        this->sell_cost_type_.set (sell_cost_type_traits::create (i, f, this));
        continue;
      }

      if (n.name () == L"sell_cost" && n.namespace_ ().empty ())
      {
        this->sell_cost_.set (sell_cost_traits::create (i, f, this));
        continue;
      }

      if (n.name () == L"buy_cost_type_1" && n.namespace_ ().empty ())
      {
        this->buy_cost_type_1_.set (buy_cost_type_1_traits::create (i, f, this));
        continue;
      }

      if (n.name () == L"buy_cost_1" && n.namespace_ ().empty ())
      {
        this->buy_cost_1_.set (buy_cost_1_traits::create (i, f, this));
        continue;
      }

      if (n.name () == L"buy_cost_type_2" && n.namespace_ ().empty ())
      {
        this->buy_cost_type_2_.set (buy_cost_type_2_traits::create (i, f, this));
        continue;
      }

      if (n.name () == L"buy_cost_2" && n.namespace_ ().empty ())
      {
        this->buy_cost_2_.set (buy_cost_2_traits::create (i, f, this));
        continue;
      }
    }

    if (!glider_code_.present ())
    {
      throw ::xsd::cxx::tree::expected_attribute< wchar_t > (
        L"glider_code",
        L"");
    }

    if (!glider_icon_name_.present ())
    {
      throw ::xsd::cxx::tree::expected_attribute< wchar_t > (
        L"glider_icon_name",
        L"");
    }

    if (!cast_time_.present ())
    {
      throw ::xsd::cxx::tree::expected_attribute< wchar_t > (
        L"cast_time",
        L"");
    }

    if (!org_speed_.present ())
    {
      throw ::xsd::cxx::tree::expected_attribute< wchar_t > (
        L"org_speed",
        L"");
    }

    if (!glide_durability_sec_.present ())
    {
      throw ::xsd::cxx::tree::expected_attribute< wchar_t > (
        L"glide_durability_sec",
        L"");
    }

    if (!repair_payment_.present ())
    {
      throw ::xsd::cxx::tree::expected_attribute< wchar_t > (
        L"repair_payment",
        L"");
    }

    if (!glider_ready_anim_.present ())
    {
      throw ::xsd::cxx::tree::expected_attribute< wchar_t > (
        L"glider_ready_anim",
        L"");
    }

    if (!glider_modeling_name_.present ())
    {
      throw ::xsd::cxx::tree::expected_attribute< wchar_t > (
        L"glider_modeling_name",
        L"");
    }

    if (!glider_ready_sound_.present ())
    {
      throw ::xsd::cxx::tree::expected_attribute< wchar_t > (
        L"glider_ready_sound",
        L"");
    }

    if (!glider_flying_sound_.present ())
    {
      throw ::xsd::cxx::tree::expected_attribute< wchar_t > (
        L"glider_flying_sound",
        L"");
    }

    if (!glider_fold_sound_.present ())
    {
      throw ::xsd::cxx::tree::expected_attribute< wchar_t > (
        L"glider_fold_sound",
        L"");
    }

    if (!sell_cost_type_.present ())
    {
      throw ::xsd::cxx::tree::expected_attribute< wchar_t > (
        L"sell_cost_type",
        L"");
    }

    if (!sell_cost_.present ())
    {
      throw ::xsd::cxx::tree::expected_attribute< wchar_t > (
        L"sell_cost",
        L"");
    }

    if (!buy_cost_type_1_.present ())
    {
      throw ::xsd::cxx::tree::expected_attribute< wchar_t > (
        L"buy_cost_type_1",
        L"");
    }

    if (!buy_cost_1_.present ())
    {
      throw ::xsd::cxx::tree::expected_attribute< wchar_t > (
        L"buy_cost_1",
        L"");
    }

    if (!buy_cost_type_2_.present ())
    {
      throw ::xsd::cxx::tree::expected_attribute< wchar_t > (
        L"buy_cost_type_2",
        L"");
    }

    if (!buy_cost_2_.present ())
    {
      throw ::xsd::cxx::tree::expected_attribute< wchar_t > (
        L"buy_cost_2",
        L"");
    }
  }

  glider_t* glider_t::
  _clone (::xml_schema::flags f,
          ::xml_schema::container* c) const
  {
    return new class glider_t (*this, f, c);
  }

  glider_t& glider_t::
  operator= (const glider_t& x)
  {
    if (this != &x)
    {
      static_cast< ::xml_schema::type& > (*this) = x;
      this->glider_code_ = x.glider_code_;
      this->glider_icon_name_ = x.glider_icon_name_;
      this->cast_time_ = x.cast_time_;
      this->org_speed_ = x.org_speed_;
      this->glide_durability_sec_ = x.glide_durability_sec_;
      this->repair_payment_ = x.repair_payment_;
      this->glider_ready_anim_ = x.glider_ready_anim_;
      this->glider_modeling_name_ = x.glider_modeling_name_;
      this->glider_ready_sound_ = x.glider_ready_sound_;
      this->glider_flying_sound_ = x.glider_flying_sound_;
      this->glider_fold_sound_ = x.glider_fold_sound_;
      this->sell_cost_type_ = x.sell_cost_type_;
      this->sell_cost_ = x.sell_cost_;
      this->buy_cost_type_1_ = x.buy_cost_type_1_;
      this->buy_cost_1_ = x.buy_cost_1_;
      this->buy_cost_type_2_ = x.buy_cost_type_2_;
      this->buy_cost_2_ = x.buy_cost_2_;
    }

    return *this;
  }

  glider_t::
  ~glider_t ()
  {
  }

  // glider_table
  //

  glider_table::
  glider_table ()
  : ::xml_schema::type (),
    glider_template_ (this)
  {
  }

  glider_table::
  glider_table (const glider_table& x,
                ::xml_schema::flags f,
                ::xml_schema::container* c)
  : ::xml_schema::type (x, f, c),
    glider_template_ (x.glider_template_, f, this)
  {
  }

  glider_table::
  glider_table (const ::xercesc::DOMElement& e,
                ::xml_schema::flags f,
                ::xml_schema::container* c)
  : ::xml_schema::type (e, f | ::xml_schema::flags::base, c),
    glider_template_ (this)
  {
    if ((f & ::xml_schema::flags::base) == 0)
    {
      ::xsd::cxx::xml::dom::parser< wchar_t > p (e, true, false, false);
      this->parse (p, f);
    }
  }

  void glider_table::
  parse (::xsd::cxx::xml::dom::parser< wchar_t >& p,
         ::xml_schema::flags f)
  {
    for (; p.more_content (); p.next_content (false))
    {
      const ::xercesc::DOMElement& i (p.cur_element ());
      const ::xsd::cxx::xml::qualified_name< wchar_t > n (
        ::xsd::cxx::xml::dom::name< wchar_t > (i));

      // glider_template
      //
      if (n.name () == L"glider_template" && n.namespace_ ().empty ())
      {
        ::std::unique_ptr< glider_template_type > r (
          glider_template_traits::create (i, f, this));

        this->glider_template_.push_back (::std::move (r));
        continue;
      }

      break;
    }
  }

  glider_table* glider_table::
  _clone (::xml_schema::flags f,
          ::xml_schema::container* c) const
  {
    return new class glider_table (*this, f, c);
  }

  glider_table& glider_table::
  operator= (const glider_table& x)
  {
    if (this != &x)
    {
      static_cast< ::xml_schema::type& > (*this) = x;
      this->glider_template_ = x.glider_template_;
    }

    return *this;
  }

  glider_table::
  ~glider_table ()
  {
  }
}

#include <istream>
#include <xsd/cxx/xml/sax/std-input-source.hxx>
#include <xsd/cxx/tree/error-handler.hxx>

namespace gdt
{
  ::std::unique_ptr< ::gdt::glider_table >
  glider_table_ (const ::std::wstring& u,
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

    return ::std::unique_ptr< ::gdt::glider_table > (
      ::gdt::glider_table_ (
        std::move (d), f | ::xml_schema::flags::own_dom, p));
  }

  ::std::unique_ptr< ::gdt::glider_table >
  glider_table_ (const ::std::wstring& u,
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

    return ::std::unique_ptr< ::gdt::glider_table > (
      ::gdt::glider_table_ (
        std::move (d), f | ::xml_schema::flags::own_dom, p));
  }

  ::std::unique_ptr< ::gdt::glider_table >
  glider_table_ (const ::std::wstring& u,
                 ::xercesc::DOMErrorHandler& h,
                 ::xml_schema::flags f,
                 const ::xml_schema::properties& p)
  {
    ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
      ::xsd::cxx::xml::dom::parse< wchar_t > (
        u, h, p, f));

    if (!d.get ())
      throw ::xsd::cxx::tree::parsing< wchar_t > ();

    return ::std::unique_ptr< ::gdt::glider_table > (
      ::gdt::glider_table_ (
        std::move (d), f | ::xml_schema::flags::own_dom, p));
  }

  ::std::unique_ptr< ::gdt::glider_table >
  glider_table_ (::std::istream& is,
                 ::xml_schema::flags f,
                 const ::xml_schema::properties& p)
  {
    ::xsd::cxx::xml::auto_initializer i (
      (f & ::xml_schema::flags::dont_initialize) == 0,
      (f & ::xml_schema::flags::keep_dom) == 0);

    ::xsd::cxx::xml::sax::std_input_source isrc (is);
    return ::gdt::glider_table_ (isrc, f, p);
  }

  ::std::unique_ptr< ::gdt::glider_table >
  glider_table_ (::std::istream& is,
                 ::xml_schema::error_handler& h,
                 ::xml_schema::flags f,
                 const ::xml_schema::properties& p)
  {
    ::xsd::cxx::xml::auto_initializer i (
      (f & ::xml_schema::flags::dont_initialize) == 0,
      (f & ::xml_schema::flags::keep_dom) == 0);

    ::xsd::cxx::xml::sax::std_input_source isrc (is);
    return ::gdt::glider_table_ (isrc, h, f, p);
  }

  ::std::unique_ptr< ::gdt::glider_table >
  glider_table_ (::std::istream& is,
                 ::xercesc::DOMErrorHandler& h,
                 ::xml_schema::flags f,
                 const ::xml_schema::properties& p)
  {
    ::xsd::cxx::xml::sax::std_input_source isrc (is);
    return ::gdt::glider_table_ (isrc, h, f, p);
  }

  ::std::unique_ptr< ::gdt::glider_table >
  glider_table_ (::std::istream& is,
                 const ::std::wstring& sid,
                 ::xml_schema::flags f,
                 const ::xml_schema::properties& p)
  {
    ::xsd::cxx::xml::auto_initializer i (
      (f & ::xml_schema::flags::dont_initialize) == 0,
      (f & ::xml_schema::flags::keep_dom) == 0);

    ::xsd::cxx::xml::sax::std_input_source isrc (is, sid);
    return ::gdt::glider_table_ (isrc, f, p);
  }

  ::std::unique_ptr< ::gdt::glider_table >
  glider_table_ (::std::istream& is,
                 const ::std::wstring& sid,
                 ::xml_schema::error_handler& h,
                 ::xml_schema::flags f,
                 const ::xml_schema::properties& p)
  {
    ::xsd::cxx::xml::auto_initializer i (
      (f & ::xml_schema::flags::dont_initialize) == 0,
      (f & ::xml_schema::flags::keep_dom) == 0);

    ::xsd::cxx::xml::sax::std_input_source isrc (is, sid);
    return ::gdt::glider_table_ (isrc, h, f, p);
  }

  ::std::unique_ptr< ::gdt::glider_table >
  glider_table_ (::std::istream& is,
                 const ::std::wstring& sid,
                 ::xercesc::DOMErrorHandler& h,
                 ::xml_schema::flags f,
                 const ::xml_schema::properties& p)
  {
    ::xsd::cxx::xml::sax::std_input_source isrc (is, sid);
    return ::gdt::glider_table_ (isrc, h, f, p);
  }

  ::std::unique_ptr< ::gdt::glider_table >
  glider_table_ (::xercesc::InputSource& i,
                 ::xml_schema::flags f,
                 const ::xml_schema::properties& p)
  {
    ::xsd::cxx::tree::error_handler< wchar_t > h;

    ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
      ::xsd::cxx::xml::dom::parse< wchar_t > (
        i, h, p, f));

    h.throw_if_failed< ::xsd::cxx::tree::parsing< wchar_t > > ();

    return ::std::unique_ptr< ::gdt::glider_table > (
      ::gdt::glider_table_ (
        std::move (d), f | ::xml_schema::flags::own_dom, p));
  }

  ::std::unique_ptr< ::gdt::glider_table >
  glider_table_ (::xercesc::InputSource& i,
                 ::xml_schema::error_handler& h,
                 ::xml_schema::flags f,
                 const ::xml_schema::properties& p)
  {
    ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
      ::xsd::cxx::xml::dom::parse< wchar_t > (
        i, h, p, f));

    if (!d.get ())
      throw ::xsd::cxx::tree::parsing< wchar_t > ();

    return ::std::unique_ptr< ::gdt::glider_table > (
      ::gdt::glider_table_ (
        std::move (d), f | ::xml_schema::flags::own_dom, p));
  }

  ::std::unique_ptr< ::gdt::glider_table >
  glider_table_ (::xercesc::InputSource& i,
                 ::xercesc::DOMErrorHandler& h,
                 ::xml_schema::flags f,
                 const ::xml_schema::properties& p)
  {
    ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
      ::xsd::cxx::xml::dom::parse< wchar_t > (
        i, h, p, f));

    if (!d.get ())
      throw ::xsd::cxx::tree::parsing< wchar_t > ();

    return ::std::unique_ptr< ::gdt::glider_table > (
      ::gdt::glider_table_ (
        std::move (d), f | ::xml_schema::flags::own_dom, p));
  }

  ::std::unique_ptr< ::gdt::glider_table >
  glider_table_ (const ::xercesc::DOMDocument& doc,
                 ::xml_schema::flags f,
                 const ::xml_schema::properties& p)
  {
    if (f & ::xml_schema::flags::keep_dom)
    {
      ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
        static_cast< ::xercesc::DOMDocument* > (doc.cloneNode (true)));

      return ::std::unique_ptr< ::gdt::glider_table > (
        ::gdt::glider_table_ (
          std::move (d), f | ::xml_schema::flags::own_dom, p));
    }

    const ::xercesc::DOMElement& e (*doc.getDocumentElement ());
    const ::xsd::cxx::xml::qualified_name< wchar_t > n (
      ::xsd::cxx::xml::dom::name< wchar_t > (e));

    if (n.name () == L"glider_table" &&
        n.namespace_ () == L"")
    {
      ::std::unique_ptr< ::gdt::glider_table > r (
        ::xsd::cxx::tree::traits< ::gdt::glider_table, wchar_t >::create (
          e, f, 0));
      return r;
    }

    throw ::xsd::cxx::tree::unexpected_element < wchar_t > (
      n.name (),
      n.namespace_ (),
      L"glider_table",
      L"");
  }

  ::std::unique_ptr< ::gdt::glider_table >
  glider_table_ (::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d,
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

    if (n.name () == L"glider_table" &&
        n.namespace_ () == L"")
    {
      ::std::unique_ptr< ::gdt::glider_table > r (
        ::xsd::cxx::tree::traits< ::gdt::glider_table, wchar_t >::create (
          e, f, 0));
      return r;
    }

    throw ::xsd::cxx::tree::unexpected_element < wchar_t > (
      n.name (),
      n.namespace_ (),
      L"glider_table",
      L"");
  }
}

#include <ostream>
#include <xsd/cxx/tree/error-handler.hxx>
#include <xsd/cxx/xml/dom/serialization-source.hxx>

namespace gdt
{
  void
  glider_table_ (::std::ostream& o,
                 const ::gdt::glider_table& s,
                 const ::xml_schema::namespace_infomap& m,
                 const ::std::wstring& e,
                 ::xml_schema::flags f)
  {
    ::xsd::cxx::xml::auto_initializer i (
      (f & ::xml_schema::flags::dont_initialize) == 0);

    ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
      ::gdt::glider_table_ (s, m, f));

    ::xsd::cxx::tree::error_handler< wchar_t > h;

    ::xsd::cxx::xml::dom::ostream_format_target t (o);
    if (!::xsd::cxx::xml::dom::serialize (t, *d, e, h, f))
    {
      h.throw_if_failed< ::xsd::cxx::tree::serialization< wchar_t > > ();
    }
  }

  void
  glider_table_ (::std::ostream& o,
                 const ::gdt::glider_table& s,
                 ::xml_schema::error_handler& h,
                 const ::xml_schema::namespace_infomap& m,
                 const ::std::wstring& e,
                 ::xml_schema::flags f)
  {
    ::xsd::cxx::xml::auto_initializer i (
      (f & ::xml_schema::flags::dont_initialize) == 0);

    ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
      ::gdt::glider_table_ (s, m, f));
    ::xsd::cxx::xml::dom::ostream_format_target t (o);
    if (!::xsd::cxx::xml::dom::serialize (t, *d, e, h, f))
    {
      throw ::xsd::cxx::tree::serialization< wchar_t > ();
    }
  }

  void
  glider_table_ (::std::ostream& o,
                 const ::gdt::glider_table& s,
                 ::xercesc::DOMErrorHandler& h,
                 const ::xml_schema::namespace_infomap& m,
                 const ::std::wstring& e,
                 ::xml_schema::flags f)
  {
    ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
      ::gdt::glider_table_ (s, m, f));
    ::xsd::cxx::xml::dom::ostream_format_target t (o);
    if (!::xsd::cxx::xml::dom::serialize (t, *d, e, h, f))
    {
      throw ::xsd::cxx::tree::serialization< wchar_t > ();
    }
  }

  void
  glider_table_ (::xercesc::XMLFormatTarget& t,
                 const ::gdt::glider_table& s,
                 const ::xml_schema::namespace_infomap& m,
                 const ::std::wstring& e,
                 ::xml_schema::flags f)
  {
    ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
      ::gdt::glider_table_ (s, m, f));

    ::xsd::cxx::tree::error_handler< wchar_t > h;

    if (!::xsd::cxx::xml::dom::serialize (t, *d, e, h, f))
    {
      h.throw_if_failed< ::xsd::cxx::tree::serialization< wchar_t > > ();
    }
  }

  void
  glider_table_ (::xercesc::XMLFormatTarget& t,
                 const ::gdt::glider_table& s,
                 ::xml_schema::error_handler& h,
                 const ::xml_schema::namespace_infomap& m,
                 const ::std::wstring& e,
                 ::xml_schema::flags f)
  {
    ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
      ::gdt::glider_table_ (s, m, f));
    if (!::xsd::cxx::xml::dom::serialize (t, *d, e, h, f))
    {
      throw ::xsd::cxx::tree::serialization< wchar_t > ();
    }
  }

  void
  glider_table_ (::xercesc::XMLFormatTarget& t,
                 const ::gdt::glider_table& s,
                 ::xercesc::DOMErrorHandler& h,
                 const ::xml_schema::namespace_infomap& m,
                 const ::std::wstring& e,
                 ::xml_schema::flags f)
  {
    ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
      ::gdt::glider_table_ (s, m, f));
    if (!::xsd::cxx::xml::dom::serialize (t, *d, e, h, f))
    {
      throw ::xsd::cxx::tree::serialization< wchar_t > ();
    }
  }

  void
  glider_table_ (::xercesc::DOMDocument& d,
                 const ::gdt::glider_table& s,
                 ::xml_schema::flags)
  {
    ::xercesc::DOMElement& e (*d.getDocumentElement ());
    const ::xsd::cxx::xml::qualified_name< wchar_t > n (
      ::xsd::cxx::xml::dom::name< wchar_t > (e));

    if (n.name () == L"glider_table" &&
        n.namespace_ () == L"")
    {
      e << s;
    }
    else
    {
      throw ::xsd::cxx::tree::unexpected_element < wchar_t > (
        n.name (),
        n.namespace_ (),
        L"glider_table",
        L"");
    }
  }

  ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument >
  glider_table_ (const ::gdt::glider_table& s,
                 const ::xml_schema::namespace_infomap& m,
                 ::xml_schema::flags f)
  {
    ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
      ::xsd::cxx::xml::dom::serialize< wchar_t > (
        L"glider_table",
        L"",
        m, f));

    ::gdt::glider_table_ (*d, s, f);
    return d;
  }

  void
  operator<< (::xercesc::DOMElement& e, const glider_t& i)
  {
    e << static_cast< const ::xml_schema::type& > (i);

    // glider_code
    //
    {
      ::xercesc::DOMAttr& a (
        ::xsd::cxx::xml::dom::create_attribute (
          L"glider_code",
          e));

      a << i.glider_code ();
    }

    // glider_icon_name
    //
    {
      ::xercesc::DOMAttr& a (
        ::xsd::cxx::xml::dom::create_attribute (
          L"glider_icon_name",
          e));

      a << i.glider_icon_name ();
    }

    // cast_time
    //
    {
      ::xercesc::DOMAttr& a (
        ::xsd::cxx::xml::dom::create_attribute (
          L"cast_time",
          e));

      a << i.cast_time ();
    }

    // org_speed
    //
    {
      ::xercesc::DOMAttr& a (
        ::xsd::cxx::xml::dom::create_attribute (
          L"org_speed",
          e));

      a << i.org_speed ();
    }

    // glide_durability_sec
    //
    {
      ::xercesc::DOMAttr& a (
        ::xsd::cxx::xml::dom::create_attribute (
          L"glide_durability_sec",
          e));

      a << i.glide_durability_sec ();
    }

    // repair_payment
    //
    {
      ::xercesc::DOMAttr& a (
        ::xsd::cxx::xml::dom::create_attribute (
          L"repair_payment",
          e));

      a << i.repair_payment ();
    }

    // glider_ready_anim
    //
    {
      ::xercesc::DOMAttr& a (
        ::xsd::cxx::xml::dom::create_attribute (
          L"glider_ready_anim",
          e));

      a << i.glider_ready_anim ();
    }

    // glider_modeling_name
    //
    {
      ::xercesc::DOMAttr& a (
        ::xsd::cxx::xml::dom::create_attribute (
          L"glider_modeling_name",
          e));

      a << i.glider_modeling_name ();
    }

    // glider_ready_sound
    //
    {
      ::xercesc::DOMAttr& a (
        ::xsd::cxx::xml::dom::create_attribute (
          L"glider_ready_sound",
          e));

      a << i.glider_ready_sound ();
    }

    // glider_flying_sound
    //
    {
      ::xercesc::DOMAttr& a (
        ::xsd::cxx::xml::dom::create_attribute (
          L"glider_flying_sound",
          e));

      a << i.glider_flying_sound ();
    }

    // glider_fold_sound
    //
    {
      ::xercesc::DOMAttr& a (
        ::xsd::cxx::xml::dom::create_attribute (
          L"glider_fold_sound",
          e));

      a << i.glider_fold_sound ();
    }

    // sell_cost_type
    //
    {
      ::xercesc::DOMAttr& a (
        ::xsd::cxx::xml::dom::create_attribute (
          L"sell_cost_type",
          e));

      a << i.sell_cost_type ();
    }

    // sell_cost
    //
    {
      ::xercesc::DOMAttr& a (
        ::xsd::cxx::xml::dom::create_attribute (
          L"sell_cost",
          e));

      a << i.sell_cost ();
    }

    // buy_cost_type_1
    //
    {
      ::xercesc::DOMAttr& a (
        ::xsd::cxx::xml::dom::create_attribute (
          L"buy_cost_type_1",
          e));

      a << i.buy_cost_type_1 ();
    }

    // buy_cost_1
    //
    {
      ::xercesc::DOMAttr& a (
        ::xsd::cxx::xml::dom::create_attribute (
          L"buy_cost_1",
          e));

      a << i.buy_cost_1 ();
    }

    // buy_cost_type_2
    //
    {
      ::xercesc::DOMAttr& a (
        ::xsd::cxx::xml::dom::create_attribute (
          L"buy_cost_type_2",
          e));

      a << i.buy_cost_type_2 ();
    }

    // buy_cost_2
    //
    {
      ::xercesc::DOMAttr& a (
        ::xsd::cxx::xml::dom::create_attribute (
          L"buy_cost_2",
          e));

      a << i.buy_cost_2 ();
    }
  }

  void
  operator<< (::xercesc::DOMElement& e, const glider_table& i)
  {
    e << static_cast< const ::xml_schema::type& > (i);

    // glider_template
    //
    for (glider_table::glider_template_const_iterator
         b (i.glider_template ().begin ()), n (i.glider_template ().end ());
         b != n; ++b)
    {
      ::xercesc::DOMElement& s (
        ::xsd::cxx::xml::dom::create_element (
          L"glider_template",
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

